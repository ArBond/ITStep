alter table рейсы
DROP Constraint p_key_рейсы

alter table автомобили
Add constraint p_key_авто Primary Key Clustered(ид_авто)

alter table автомобили alter column ид_авто int
not null