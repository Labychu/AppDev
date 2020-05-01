<?php
$ID = $_POST['ID'];
$name = $_POST['name'];
$today = date("Y-m-d H:i:s");
$record = $today . ", " . $ID . ", " . $name . "\n";

$file = "sound.log";
if (file_exists($file))
	$fp = fopen($file, "a");
else
	$fp = fopen($file, "w");
fwrite($fp, $record);
fclose($fp);
echo "From ThiDinh e1900323\n";
?>
