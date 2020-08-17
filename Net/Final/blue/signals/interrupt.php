<?php  session_start(); if(!isset($_SESSION["id"])) { header("Location: ../index.php"); }  ?>

<html> 
<head> 
  <title>Traffic Management System</title> 
  <meta name="viewport" content="width=device-width, initial-scale=1"> 
  <link rel="stylesheet" href="../assets/css/jquery.mobile-1.2.0.css" />
  <script src="../assets/js/jquery-1.8.2.min.js"></script>
  <script src="../assets/js/jquery.mobile-1.2.0.min.js"></script>
</head> 
<body> 

<div data-role="page">

<a href = "../">
  <div data-role="header">
    <h1>Traffic Management System</h1>
  </div><!-- /header -->
</a>

  <div align = "left"> 
<!----Start Content Body---->
<h1 align = "center">Interrupt</h1>


<?php
if(count($_GET)>0) {
if($_GET["sig"]&&$_GET["stat"]){
echo "<div align = 'center'><a href = 'status.php?signo=".$_GET["sig"]."'>Back</a></div>";
include_once("../db.php");
$sigstat = 0;
$q = "SELECT * FROM sigstat WHERE signo = '".$_GET["sig"]."'";
$result = mysqli_query($conn, $q);
$row  = mysqli_fetch_array($result);
if(is_array($row)) {
$sigstat = $row['sigstat'];
} else {
echo "Database parameters seems mismatch  please contact developer...";
}
$q = "SELECT * FROM interrupt WHERE signo = '".$_GET["sig"]."'";
$result = mysqli_query($conn, $q);
$row  = mysqli_fetch_array($result);
if(is_array($row)) {
$intr = $row['intr'];
$dir = $row['dir'];
} else {
echo "Database parameters seems mismatch  please contact developer...";
}
  if($dir =='N'){
	$dir = "North";
  }
  else if($dir =='W'){
	$dir = "West";
  }
  else if($dir =='S'){
	$dir = "South";
  }
  else if($dir =='E'){
	$dir = "East";
  }
  

echo "<h2 align = 'center'>";
if($sigstat == $_GET["stat"]){
//echo "<script>alert('Signal is already open for this direction.');</script>";
echo "Signal is already open for this direction.";
}
else if($intr == 1){
//echo "<script>alert('Signal is already interrupted from ".$dir."');</script>";
echo "Signal is already interrupted from ".$dir."";
}
else if($intr != 1 && $sigstat != $_GET["stat"]){
$q = "UPDATE `interrupt` SET `intr`= '1', `dir` = '".$_GET["stat"]."' WHERE `signo`= '".$_GET["sig"]."'";
$res = mysqli_query($conn, $q);
if($res)
echo "Interrupt signal from ".$dir." is received please wait for time equivalent to yellow signal time";
else 
echo "Interrupt failed to update query";
}
else{
echo "<script>alert('Error x0.1.2');</script>";
echo "Error x0.1.2";
}
}
else{
echo "Wrong parameters";
}
}
echo "</h2>";
?>





<!----End Content Body---->  
  </div><!-- /content -->

 <!----Footer---->
  <div data-role="footer" data-position="fixed">
    <div data-role="navbar">
      <ul>
        <li><a href="signals_list.php" data-icon="gear" class="ui-btn-active ui-state-persist">Signals List</a></li>
        <li><a href="../signalbreak/signalbreak.php" data-icon="refresh">Signal break</a></li>
        <li><a href="../priority1/priority1.php" data-icon="menu">Priority 1 vehicles</a></li>
		<li><a href="../logout.php"><?php echo "<b>".$_SESSION["name"]."</b>,"; ?>	Logout</a>		</li>
      </ul>
    </div>
  </div>

</div><!-- /page -->

</body>
</html>
