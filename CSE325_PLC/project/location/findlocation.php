
<?php
	echo "This is used to find location";

?>

<?php
 
$a['registrationID'] =htmlspecialchars($_POST['user_name']);  /*Your AloAshbei Username*/
$a['password'] =htmlspecialchars($_POST['password']);  /*Your Aloashbei Password*/
$a['msisdn'] =(int)"88".htmlspecialchars($_POST['phone_number']); /*Your registered number.*/
 
$soap_url='http://localhost/location/WebService_Aloashbei_LBS_WS.wsdl';
$soap = new SoapClient($soap_url);

$response=$soap->requestLocation( array ("LBSRequest" => $a) ); 


$i = 0 ;
$arr;
foreach( $response as $value)
{

	foreach($value as $secondvalue)
	{
		$arr[$i] = $secondvalue;
		$i++;
		echo "<br/>";

	}


}

echo "Latitude is ".$arr[0];

echo "Longitude is ".$arr[1];

echo '<pre>';
print_r($response);
echo '</pre>';

?>
