<?php
if(count($_GET)>0) {
if($_GET["signo"]&&$_GET["state"]){
include_once("../db.php");
$sigstat = 0;
$q = "SELECT * FROM sigstat WHERE signo = '".$_GET["signo"]."'";
$result = mysqli_query($conn, $q);
$row  = mysqli_fetch_array($result);
if(is_array($row)) {
$sigstat = $row['sigstat'];
} else {
echo "Database parameters seems mismatch  please contact developer...";
}

if($sigstat != $_GET["state"]){
$q = "UPDATE `sigstat` SET `sigstat` = '".$_GET["state"]."' WHERE `signo`= '".$_GET["signo"]."'";
$res = mysqli_query($conn, $q);
}
}
}
?>