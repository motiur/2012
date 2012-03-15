<?php

echo "Seding MMS";
?>
<?php
 
$a['registrationID'] = "***";  /*Your AloAshbei Username*/
$a['password'] = "***";  /*Your Aloashbei Password*/
$a['sourceMsisdn'] = '***'; /*Your registered number.*/
$a['destinationMsisdn'] = '***'; /*Number you are sending to.*/
$a['mmsPort'] = '5001';

$a['charge'] = 0.00 ;
$a['chargedParty'] = '***'; /*Same as sourceMSISDN.*/
$a['contentArea'] = 'gpgp_psms';
$a['msgSubject'] = 'Message Subject'; /*The message being sent.*/
$a['msgBody'] = 'Message Body'; /*The message being sent.*/
$a['contentFilename'] = 'nopic'; /*The message being sent.*/
$a['msgContent'] = 'Hello World'; /*The message being sent.*/
 
$soap_url='http://localhost/location/mms.wsdl';
$soap = new SoapClient($soap_url);

$response=$soap->sendMMS( array ("SendMMSRequest" => $a) ); 
 
echo '<pre>';
print_r($response);
echo '</pre>';
?>
