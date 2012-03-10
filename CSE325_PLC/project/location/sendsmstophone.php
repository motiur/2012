<?php
	echo "Sending SMS to phone";
?>
<?php
 
$a['registrationID'] = "motiur_rahman";  /*Your AloAshbei Username*/
$a['password'] = "hello012";  /*Your Aloashbei Password*/
$a['sourceMsisdn'] = '8801738023926'; /*Your registered number.*/
$a['destinationMsisdn'] = '8801738023926'; /*Number you are sending to.*/
$a['smsPort'] = 7424;
$a['msgType'] = 4;
$a['charge'] = 0.00 ;
$a['chargedParty'] = '8801738023926'; /*Same as sourceMSISDN.*/
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
