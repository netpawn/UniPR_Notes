-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
--Usare l'algebra relazionale per esprimere il vincolo che impedisce agli
--allievi di avere più lezioni settimanali per la stessa materia

--SQL
alter table orario
    add constraint no_stakanovisti
    unique(allievo, materia);


--Algebra relazionale
ennuple che violano il vincolo = {}

o1 := orario
o2 := orario

SEL_{o1.allievo = o2.allievo and o1.materia = o2.materia
    and (o1.aula != o2.aula OR
         o1.giorno_sett != o2.giorno_sett or
         o1.ora != o2.ora)
    (o1 JOIN o2) = { }
    --sfruttando l'esistenza della chiave primaria

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

1)
CREATE TABLE tessere_elettorali(
  numero INT NOT NULL,
  sezione_distretto VARCHAR(50) NOT NULL,
  sezione_numero INT NOT NULL,
  persona VARCHAR(16) FOREIGN KEY REFERENCES persone(codice_fiscale) NOT NULL,
  data_emissione DATE NOT NULL,

PRIMARY KEY (numero),
FOREIGN KEY (sezione_numero, sezione_distretto) REFERENCES sezioni(numero, distretto),
FOREIGN KEY (persona) REFERENCES persone(codice_fiscale)
);

2)
ALTER TABLE tessere_elettorali(
  add constraint no_doppio_votisti
  unique persona;
)

3)
create or replace view elettorato_attivo(sezione_distretto, sezione_numero, persona,
                                         numero_tessera, nome, cognome, data_nascita) as

select te.sezione_distretto, te.sezione_numero, te.persona, te.numero, p.cognome, p.nome, p.data_nascita --dalla view
from tessere_elettorali te, persone p
where te.persona = p.codice  --join
  and cast('2015-04-01' as date) - p.data_nascita >= 18*365 -- per la maggiore età
  and (p.data_morte is null or p.data_morte > '2015-04-01') -- non è morto acnora
  --and almeno_diciotto_anni_alla_data(p.data_nascita, '2015-04-01')
  and te.data_emissione < '2015-04-01'; -- data emissione prima delle votazioni


4)
delete from ... --voti_espressi
select * from voti_espressi ve where ve.tessera not in (select tessera from elettorato_attivo);
-- OPPURE
select * from voti_espressi ve where not exists ( select * from elettorato_attivo ea where ea.numero_tessera = ve.tessera);


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

persone(_nome_, reddito)
paternità(padre_fk, figli_fk)

--trovare i padri i cui figli hanno reddito maggiore di 20

select padre from paternità pt --tira fuori il padre
where not exists(
--trovami un figlio di questo padre
select * from persone p, paternità pt2  --tira fuori i figli, tutti
where pt2.padre = pt.padre  --unisce i due
and pt2.nome = pt2.figlio and p.reddito <= 20 );

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
5)

CREATE VIEW voti_espressi_entro_mezziogiorno(distretto, numero_voti) as
SELECT te.sezione_distretto, count(*)
FROM voti_espressi ve join tessere_elettorali te on ve.tessera = te.numero -- join esplicito giusto così, for fun
WHERE ve.ora_voto <= '12:00' GROUP BY te.sezione_distretto;

CREATE VIEW elettorato_attivo_del_distretto(distretto, numero_elettori) as
SELECT sezione_distretto, count(*)
FROM elettorato_attivo
GROUP BY sezione_distretto;


SELECT v.distretto, (v.numero_voti *100) / e.numero_elettori as percentuale_affluenza_entro_mezzogiorno
FROM voti_espressi_entro_mezziogiorno v, elettorato_attivo_del_distretto e
WHERE v.distretto = e.distretto

-----SE FOSSE PER TUTTI I DISTRETTI
-- common table expressions -> servono per viste temporanee

with numero_voti_alle_dodici(num_voti) as
SELECT count(*),
FROM voti_espressi
WHERE ora_voto <= '12:00'
numero_elettori (num_elett) as
select count(*) from elettorato_attivo

select (num_voti * 100) / numero_elett
from numero_voti_alle_dodici, numero_elettori;
------- MA E' MEGLIO FOLDARLA --------------

6) Usando algebra rel, vincolo NO voti che non sono fra le 8:00 e le 22:30
--SQL
ALTER TABLE voti_espressi
add constraint orario_rispettato
check (ora_voto between '8:00' and '22:30');

--ALGEBRA REL (sel righe che violano)

SEL_{ora_voto < '8:00' or ora_voto > '22.30'}(voti_espressi) = {}

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

 7)

 select vs.*, p.cognome, p.nome
 from voti_scrutinati vs left outer join persone p on vs.candidato = p.codice_fiscale;

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-- NO stesso indirizzo per due sezioni elettorali

ALTER TABLE sezione_distretto(
  add constraint no_stessa_sede
  unique indirizzo;
)


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-------------------------------------------PARZIALE 20140505-----------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

1)
CREATE TABLE voti(
  studente INT NOT NULL,
  materia INT NOT NULL,
  tipo VARCHAR(7) NOT NULL,
  voto NUMERIC(3,1) NOT NULL,
  data_voto DATE NOT NULL,
  check (tipo in 'scritto' or 'orale'),
  check (voto BETWEEN '0.0' and '10.0'),
  --unique studente, materia

    PRIMARY KEY studente, materia, data_del_giorno,

  FOREIGN KEY (studente) REFERENCES studenti(matricola),
  FOREIGN KEY (materia) REFERENCES meterie(codice)
);


2)
ALTER TABLE docenti
    add constraint non_troppo_bro
    unique docenti, classe


3)
DELETE FROM voti
WHERE materia in (select codice from materia where nome in (matematica, informatica))




4) aumentare per tutti gli sutdenti il voto di musica < di 6
ALTER TABLE voti (
  set voto = voto + 1 where voto < 6 and materia = 'Musica'
);

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

--Algebra relazionale, vincolo che impedisce ad uno studente di conseguire un voto in una materia se la
--classe dello studente non ha effettivamente associato un insegnamento per quella materia

--SQL
check(not exists(
select
from voti v, studenti s
where v.stuente = s.matricola
and not exists (select * from insegnamenti i
  where i.classe = s.classe
  and i.materia = v.materia
    )
  )
);


--ALGEBRA REL

PROJ_{voti.materia, studenti.classe}
  (voti JOIN_{voti.studenti = studenti.matricola} studenti) 


PROJ_{materia, classe} (insegnamenti) = { }
