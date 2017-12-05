
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

alter PROCEDURE FirstProc
	 @in_a int, @in_b int,@out_rezult int output
AS
BEGIN
	DECLARE @sql_count int=(select count(*) from Table_1);
	SET @out_rezult=@in_a+@in_b+@sql_count;

END
GO
