SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO


alter PROCEDURE FirstProc
	 @datein date, 
	 @result datetimeoffset output
AS
BEGIN
	SET @result = CONVERT(date, GETDATE()) - @datein;
END
GO
