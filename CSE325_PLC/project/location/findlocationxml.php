<?php
	
	echo "This is location xml";

?>

<?php

	$latitude = 23.815334;
	$longitude = 90.426096;
	$xml1 =simplexml_load_file("http://maps.googleapis.com/maps/api/geocode/xml?latlng=".$latitude.",".$longitude."&sensor=true");


	
	

	
	

	
	 //$result1=$xml1->xpath("result/formatted_address");//gives all the addresses
	
	
	/*foreach ( $result1 as $value)
	{
		echo $value;
		echo "</br>";	
	}*/	
	//echo $result1[0];
	
	echo "</br>";
	
	//echo "</br>";
	
	//print_r($result1);


	$starting_place = "Lalbagh,Dhaka";
	$ending_place = "North South University,Dhaka";
	
	$via = "Moakhali,Dhaka";
	$travel_mode = "driving";

	$xml2=simplexml_load_file("http://maps.googleapis.com/maps/api/directions/xml?origin=".$starting_place."&"."destination=".$ending_place."&waypoints=optimize:true|".$via."&mode=".$travel_mode."&sensor=true");

	$instructions=$xml2->xpath("route/leg/step/html_instructions");//gives the road direction
	


	$totaldistance = 0;
	$totaltime = 0;	
	foreach ( $instructions as $value)
	{
		echo $value;
		echo "</br>";	
		
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

	echo "<b>Totaldistance is ".$totaldistance." meters , totaltime taken is ".$totaltime." seconds</b>";
	

?>
