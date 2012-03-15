<html>
<body>



	<form action="latitudelongitude.php" method="post">
			<div align = "center">
			
			<h1>Using latitude and longitude</h1>

			<hr/>			
			<p>Travel Medium</p>
			<br/>
			
			<input type="radio" name="mode" value="driving" /> Driving<br /></input>
			<br/>
			<br/>
			<input type="radio" name="mode" value="walking" /> Walking<br /></input>
			<br/>
			<br/>
			<input type="radio" name="mode" value="bicycling" /> Bicycling<br /></input>
			<br/>
			<br/>
			Starting Latitude:<input type="text" name="lat1"></input>
			<br/>
			<br/>
			Starting Longitude:<input type="text" name="long1"></input>
			<br/>
			<br/>
			Ending Latitude:<input type="text" name="lat2"></input>
			<br/>
			<br/>
			Ending Latitude:<input type="text" name="long2"></input>
			<br/>
			<br/>
			Travel Via:<input type="text" name="via"></input>
			<br/>
			<input type="submit" name="submit" value="Send"/>
			</div>

	</form>

</body>

</html>

