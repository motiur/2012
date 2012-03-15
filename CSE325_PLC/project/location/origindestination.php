<?php
	
	echo "<div align = 'center'><h1>Using origin and destination</h1></div>";
	
	echo "<br/>";

?>

<?php
	
	echo "</br>";
	
	
	$starting_place = htmlspecialchars($_POST['origin']);
	$ending_place = htmlspecialchars($_POST['destination']);
	
	$via = htmlspecialchars($_POST['via']);

	$travel_mode = htmlspecialchars($_POST['mode']);


	$xml2=simplexml_load_file("http://maps.googleapis.com/maps/api/directions/xml?origin=".$starting_place."&"."destination=".$ending_place."&waypoints=optimize:true|".$via."&mode=".$travel_mode."&sensor=true");

	$instructions=$xml2->xpath("route/leg/step/html_instructions");//gives the road direction
	


	$totaldistance = 0;
	$totaltime = 0;	
	echo "<div align = 'center'>";
	foreach ( $instructions as $value)
	{
		echo $value;
		echo "<br/>";
		echo "<br/>";	
		
	}
	

	$distance=$xml2->xpath("route/leg/step/distance/value");//gives the road direction
	foreach ( $distance as $value)
	{
		//echo $value;
		//echo "</br>";	
		$totaldistance+= $value;	
	}

	$time=$xml2->xpath("route/leg/step/duration/value");//gives the road direction
	foreach ( $time as $value)
	{
		//echo $value;
		//echo "</br>";	
		$totaltime+= $value;
			
	}
	echo "<br/>";

	echo "<h3>Totaldistance is ".$totaldistance." meters , totaltime taken is ".$totaltime." seconds</h3>";
	
	echo "</div>";	
	
	
?>
