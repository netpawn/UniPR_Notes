-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

musei(nomepk, città)
artisti(nomepk, anno nascita, anno morte⋆, nazionalità)
opere(codicepk, artista⋆fk , titolo, anno, museofk , tipo, altezza, larghezza, profondità⋆)
prestiti(operapkfk , museofk , data inizio, data fine)
restauri(operapkfk , data inizio, data fine⋆)

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
1. Scrivere l’istruzione DDL per la definizione della relazione prestiti includendo, oltre ai vincoli indicati nello schema, gli ovvi vincoli di ennupla.

CREATE TABLE prestiti (
  opera INT NOT NULL,
  museo VARCHAR(20) NOT NULL,
  data_inizio DATE NOT NULL,
  data_fine DATE NOT NULL,

  CHECK (data_inizio < data_fine),
  PRIMARY KEY opera,
  FOREIGN KEY opera REFERENCES opere(codice),
  FOREIGN KEY museo REFERENCES musei(nome)
)


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

2. Il tipo di un’opera può essere “dipinto”, “scultura” o “installazione”. Aggiungere alla tabella opere un vincolo di integrità che,
 oltre al requisito suddetto, imponga che la profondità sia valorizzata per tutte le opere di tipo diverso da “dipinto”.

 ALTER TABLE opere (
   ADD CONSTRAINT uno_dei_tre
   check ( (tipo = 'dipinto') or (tipo in ('scultura', 'installazione') and profondità is not null ))
 );


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

3. Eliminare dal database tutti i prestiti conclusi da almeno cinque anni.

DELETE FROM prestiti WHERE current_date - data_fine >= 365 * 5;


-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

4. Elencare gli artisti le cui opere non sono mai state oggetto di restauro.

SELECT o.artista from opere o
WHERE o.codice NOT IN (SELECT r.opera FROM restauri r);

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------


5. Definire la vista relazionale opere fruibili, che associa ad ogni museo le opere che sono di proprietà del museo oppure sono
attualmente concesse in prestito a questo museo da parte di altri musei e sono effettivamente fruibili per il pubblico,
in quanto non sono oggetto di restauro e non sono state concesse in prestito ad altro museo.
Nota: fare riferimento alla situazione valida in data odierna.

CREATE OR REPLACE VIEW opere_fruibili(
    opera, museo) as
    SELECT o.titolo, musei.nome
    FROM opere o JOIN musei m JOIN prestiti p
    WHERE o.codice NOT IN (SELECT opera FROM restauri WHERE current_date>= data_inizio and current_date < data_fine) --opera non in restauro
    AND (presiti.museo = opere.museo AND prestiti.opear = opere.codice) --opera è in prestito
    OR (opere.museo = musei.nome AND codice NOT IN (SELECT opere FROM prestiti)) -- opera di proprietà non in prestito
)

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

6. Durante tutto il mese di maggio 2016, il museo “Uffizi” di Firenze propone una mostra sull’artista Giotto.
A tale scopo, si fa prestare (da tutti gli altri musei) le opere di Giotto di loro proprietà, per il periodo dal 15 aprile al 5 giugno 2016.
Modificare la tabella prestiti per tenere traccia di questo evento. Nota: per semplicità, ignorare eventuali prestiti
preesistenti di opere di Giotto che riguardano il periodo in questione.

ALTER TABLE presiti (
ADD COLUMN eventi VARCHAR(10)
);

INSERT INTO prestiti(opera, museo, data_inizio, data_fine, eventi) VALUES ('nome_opera', 'Uffizi', '2016-05-15', '2016-07-05', 'Evento mostra Giotto');
-- l'operazione si ripete per ogni opera prestata da altri musei al musei "Uffizi".

-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------


7. Elencare gli artisti che, nell’insieme di tutti i musei, hanno almeno 10 opere, ordinandoli in base al numero di opere realizzate (a parità di opere,
   usare l’ordinamento in base al nome dell’artista). Per ogni artista, indicare il numero di musei che possiedono almeno un’opera dell’artista.

   SELECT artista, COUNT(*) as num_opere, COUNT(DISTINCT museo) as num_musei
   FROM opere
   GROUP BY artista HAVING COUNT(*) >= 10;
   ORDER BY num_opere, artista;



   8. Usando l’algebra relazionale, codificare il vincolo di chiave primaria per la relazione musei.

   m1:= musei
   m2:= musei
   SEL_{m1.nome = m2.nome} (MUSEI) = { }
