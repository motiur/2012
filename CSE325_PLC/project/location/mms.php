<?php

echo "Seding MMS";
?>
<?php
 
$a['registrationID'] = "motiur_rahman";  /*Your AloAshbei Username*/
$a['password'] = "hello012";  /*Your Aloashbei Password*/
$a['sourceMsisdn'] = '8801738023926'; /*Your registered number.*/
$a['destinationMsisdn'] = '8801738023926'; /*Number you are sending to.*/
$a['mmsPort'] = '5001';

$a['charge'] = 0.00 ;
$a['chargedParty'] = '8801738023926'; /*Same as sourceMSISDN.*/
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
/*
<s:element minOccurs="0" maxOccurs="1" form="unqualified" name="registrationID" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="password" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="sourceMsisdn" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="destinationMsisdn" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="mmsPort" type="s:string" />
            <s:element minOccurs="1" maxOccurs="1" form="unqualified" name="charge" type="s:double" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="chargedParty" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="contentArea" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="msgSubject" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="msgBody" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="contentFileName" type="s:string" />
            <s:element minOccurs="0" maxOccurs="1" form="unqualified" name="msgContent" type="s:string" />
  */      

?>
