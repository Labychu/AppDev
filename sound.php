<?php
// There is a exact copy of this file (exclue the comment line)
// in my public_html folder in my U:/
$maxVal = $_POST['maxVal'];
$peakNum = $_POST['peakNum'];
$ID = $_POST['ID'];
$today = date("Y-m-d H:i:s");
$record = $today . ", " . $maxVal . ", ". $peakNum. ", " . $ID . "\n";

$file = "sound.log";
if (file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);
echo "From ThiDinh e1900323\n";
?>
