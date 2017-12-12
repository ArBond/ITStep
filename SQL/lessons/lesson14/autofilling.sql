declare @counter int = 100000
declare @subject_id varchar(10)

while @counter < 1000000
begin

declare @id varchar(10)
set @id = 'TCH' + convert(varchar(10), @counter)
set @counter += 1

select TOP 1 @subject_id =  subject_id  FROM subjects ORDER BY NEWID()

insert into teachers values (@id, 'second_name', 'first_name', 'patronymic', @subject_id)

end
