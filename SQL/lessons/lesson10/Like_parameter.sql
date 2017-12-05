@location nchar(20),
   @time time,
   @date date
AS
   select 
       DonationsTruck.VechileId, Phone, Location, [Date], [Time]
   from 
       Vechile, DonationsTruck
    where 
       Vechile.VechileId = DonationsTruck.VechileId
       and (((Location like '%'+@location+'%') or (Location like '%'+@location) or (Location like @location+'%') ) or [Date]=@date or [Time] = @time)