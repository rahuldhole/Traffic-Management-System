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

  <div align = "center"> 
<!----Start Content Body---->

  <h1>Defaulter details</h1>
<table border = '0' style = 'color : white' align = 'center'><tr style=
'background:#0193e9 ' style='font-family:Comic Sans MS' align = 'center'>
<td>Name</td><td>Mobile</td><td>Address</td><td>Signal break from</td><td>Photo</td><td>Signal breaking Image and time</td></tr>

<?php
include_once("../db.php");
$q = "SELECT * FROM defaulters WHERE id = '".$_GET["id"]."'";
$result = mysqli_query($conn, $q);
$row  = mysqli_fetch_array($result);
if($row['sigside']=='N')
$sigside = "North";
else if($row['sigside']=='W')
$sigside = "West";
else if($row['sigside']=='S')
$sigside = "South";
else if($row['sigside']=='E')
$sigside = "East";
else 
$sigside = "Unknown";
$q = "SELECT * FROM signals_break WHERE id = '".$_GET["id"]."'";
$result = mysqli_query($conn, $q);
$row1  = mysqli_fetch_array($result);

	echo"<tr style='background:silver' style='font-family:Comic Sans MS' align = 'center'>";
	echo "<td>".$row['name']."</td>";
	echo "<td>".$row['contact']."</td>";
	echo "<td>".$row['address']."</td>";
	echo "<td>".$sigside." side of ".$_GET["signo"]." signal</td>";
	if($row['photo'])
	echo '<td><img  height = "240" width = "360" src="data:image/jpeg;base64,'.base64_encode($row['photo']). ' " /></td>';
	else
	echo '<td><img  height = "240" width = "360" src= "../images/default-photo.png" /></td>';
	echo '<td><img  height = "240" width = "360" src="data:image/jpeg;base64,'.base64_encode($row1['image']). ' " />'.'<hr />'.$row1['time'].'</td>';
?> 
</tr>
</table><hr />
<a href = "editDefaulter.php?id=<?php echo $_GET["id"]; ?>&signo=<?php echo $_GET["signo"]; ?>">Click here to modify information of this defaulter</a>
  
  
<!----End Content Body---->  
  </div><!-- /content -->

 <!----Footer---->
  <div data-role="footer" data-position="fixed">
    <div data-role="navbar">
      <ul>
        <li><a href="../signals/signals_list.php" data-icon="gear" class="ui-btn-active ui-state-persist">Signals List</a></li>
        <li><a href="signalbreak.php" data-icon="refresh">Signal break</a></li>
        <li><a href="../priority1/priority1.php" data-icon="menu">Priority 1 vehicles</a></li>
		<li><a href="../logout.php"><?php echo "<b>".$_SESSION["name"]."</b>,"; ?>	Logout</a>		</li>
      </ul>
    </div>
  </div>

</div><!-- /page -->

</body>
</html>
