<html>
<body>



	<form action="origindestination.php" method="post">

			<div align = "center">
			<h1>Using origin and destination</h1>
			<hr/>
			<br/>
			<p>Travel Medium</p>
			<br/>
			
			<input type="radio" name="mode" value="driving" /> Driving<br /></input>
			<br/>
			
			<input type="radio" name="mode" value="walking" /> Walking<br /></input>
			<br/>
			
			<input type="radio" name="mode" value="bicycling" /> Bicycling<br /></input>
						
			<br/>
			Starting Point:<input type="text" name="origin"></input>
			<br/>
			<br/>
			Ending Point:<input type="text" name="destination"></input>
			<br/>
			<br/>
			Travel Via:<input type="text" name="via"></input>
			<br/>
			<br/>
			<input type="submit" name="submit" value="Send"/>
			</div>

	</form>

</body>

</html>

