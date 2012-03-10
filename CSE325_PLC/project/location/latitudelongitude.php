<?php
	
	echo "<div align = 'center'><h1>Using latitude and longitude</h1></div>";
	
	echo "<br/>";

?>



<?php

	

	//starting place 
	$latitude1 = htmlspecialchars($_POST['lat1']);
	$longitude1 = htmlspecialchars($_POST['long1']);
	$xml1 =simplexml_load_file("http://maps.googleapis.com/maps/api/geocode/xml?latlng=".$latitude1.",".$longitude1."&sensor=true");


		
	 $result1=$xml1->xpath("result/formatted_address");//gives all the addresses
	
	if (!$result1[0]){exit(1);} 			

	echo $result1[0];


	echo "<br/>";
	
	//ending place 
	$latitude2 = htmlspecialchars($_POST['lat2']);
	$longitude2 = htmlspecialchars($_POST['long2']);
	$xml2 =simplexml_load_file("http://maps.googleapis.com/maps/api/geocode/xml?latlng=".$latitude2.",".$longitude2."&sensor=true");


		
	 $result2=$xml2->xpath("result/formatted_address");//gives all the addresses
	
	if (!$result1[0]){exit(2);}			

	echo $result2[0];



	$starting_place = $result1[0];
	$ending_place = $result2[0];
	
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
		echo "</br>";	
		
	}
	echo "</div>";
	

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

	if (($totaldistance == 0 )||($totaltime ==0)||!$result1[0]||!$result2[0]){echo "<br/><b>Mate sorry to disappoint</b>";}
	else
	{
		echo "<h3>Totaldistance is ".$totaldistance." meters , totaltime taken is ".$totaltime." seconds</h3>";
	}	

	echo "</div>";

	


?>


