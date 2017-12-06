SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

alter FUNCTION drivers_with_experience
(@experiense int)
RETURNS TABLE 
AS
RETURN 
(
	SELECT *from водители where стаж >= @experiense
)
GO
