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

  <div> 
<!----Start Content Body---->
<?php
if($_GET["vid"]&&$_GET["vname"]){
include_once("../db.php");
$sql = "SELECT * FROM p1vehicles WHERE id = '".$_GET["vid"]."'";
$result = mysqli_query($conn, $sql);
$row  = mysqli_fetch_array($result);
?>

<h2 align = "center">Status of <?php echo $_GET["vname"]; ?></h2>

<table border = '0' style = 'color : white' align = 'center'><tr style=
'background:#0193e9 ' style='font-family:Comic Sans MS' align = 'center'>
<td>Latitude</td><td>Longitude</td><td>Last Location</td><td>Time</td></tr>
<?php
	echo"<tr style='background:silver' style='font-family:Comic Sans MS' align = 'center'>";
	echo "<td>".$row['lat']."</td><td>".
	$row['long']."</td>"."<td>".
	$row['address']."</td>"."<td>".
	$row['time']."</td>"."<td>";
	echo"</tr>";
?>  
</table>
  
  
  <?php 
  }
  ?>
<!----End Content Body---->  
  </div><!-- /content -->

 <!----Footer---->
  <div data-role="footer" data-position="fixed">
    <div data-role="navbar">
      <ul>
        <li><a href="../signals/signals_list.php" data-icon="gear" class="ui-btn-active ui-state-persist">Signals List</a></li>
        <li><a href="../signalbreak/signalbreak.php" data-icon="refresh">Signal break</a></li>
        <li><a href="priority1.php" data-icon="menu">Priority 1 vehicles</a></li>
		<li><a href="../logout.php"><?php echo "<b>".$_SESSION["name"]."</b>,"; ?>	Logout</a>		</li>
      </ul>
    </div>
  </div>

</div><!-- /page -->

</body>
</html>
