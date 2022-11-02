-- censimenti (_anno_)
create table censimeti (
    anno integer not null primary key, 
    check ( anno >= 1860 )
); 
-- luoghi (_codice_, nome, tipo, continente^*) 

-- check ( tipo in ('C', 'S') )

-- check ( tipo = 'S' AND continente is not null ) 
--          OR
--       ( tipo = 'C' AND continente is null) )

-- check continente (continente in ('Europa', 'Africa', 'Asia', 'America', 'Oceania') )

-- province (_codice_, nome) 
-- comuni ( (_censimenti_)fk (luighi), superficie, (provincia)fk ) 
--check (comune1<comune2)

-- comuni_confinanti ( (_comune1_)fk, (_comune2_)fk )

-- individui (_cf_, anno_nascita, (luogo_nascita)_fk(luoghi) )

-- individui_censiti ( (censimento)fk, (_individuo_)fk, (occupazione)fk, (comune_occupazione)_fk(comuni), (titolo_studio)fk, 
--                   (cittadinanza)_fk), (censimento_dich, individuo_dich)_fk(dichiarante) )
--
-- foreign key (censimento, ind_dichiarante)
-- references dichiarantiU(censiment, individuo)
-- check (relazione_con_dichiarante = 'dichiarante' se e solo se individuo = ind_dichiarante)


 
-- dichiaranti ( (_censimento_, _individuo_)fk(individui_censiti), (comune_residenza)_fk(comuni), via, numero_civico) 

-- occupazioni (_codice_, nome ) 
-- cittadinanza (_nome_ )

--

