<?php
	echo "Sending SMS to phone";
?>
<?php
 
$a['registrationID'] = "***";  /*Your AloAshbei Username*/
$a['password'] = "***";  /*Your Aloashbei Password*/
$a['sourceMsisdn'] = '***'; /*Your registered number.*/
$a['destinationMsisdn'] = '***'; /*Number you are sending to.*/
$a['smsPort'] = 7424;
$a['msgType'] = 4;
$a['charge'] = 0.00 ;
$a['chargedParty'] = '***'; /*Same as sourceMSISDN.*/
$a['contentArea'] = 'gpgp_psms';
$a['msgContent'] = 'Hello World'; /*The message being sent.*/
 
$soap_url='http://localhost/location/WebService_GP_ADP_BizTalk_SMS_Orchestrations.wsdl';
$soap = new SoapClient($soap_url);

if(!$soap->sendSMS( array ("SendSMSRequest" => $a) ))
{
	echo "Sorry mate";
} 

else 
{
	echo '<pre>';
	print_r($response);
	echo '</pre>';
}
?>
