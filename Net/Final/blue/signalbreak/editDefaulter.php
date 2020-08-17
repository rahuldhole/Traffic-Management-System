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

  <h1>Modify defaulter's details</h1>
  
  <?php 
  if(count($_POST)>0){
  $url = 'editDefaulter.php?id='.$_POST['id'].'&signo='.$_POST['signo'];
include_once("../db.php");		
if($_POST["image_name"]&&$_POST["mob"]&&$_POST["add"]&&$_POST["id"]&&$_POST['signo']){
$sql = "UPDATE `defaulters` SET `name` =  '".$_POST["image_name"]."', `contact` = '".$_POST["mob"]."', `address` = '".$_POST["add"]."' WHERE `id` ='".$_POST["id"]."'";
mysqli_query($conn, $sql) or die("Error in Query insert: " . mysqli_error()); 	
        

	  
		
//header("location: $url");
}
else{
echo "<script>alert('Something is missing...');</script>";
header("location: $url");
}
}
?>
  
<table align = "center">
<td>
  <form action="" method="post"  enctype="multipart/form-data">
Name:<input type="textarea" name="image_name" id="" /><br />
Mobile:<input type="textarea" name="mob" id="" /><br />
Address:<input type="textarea" name="add" id="" /><br />
<input type="hidden" name="id" value="<?php echo $_GET["id"]; ?>" />
<input type="hidden" name="signo" value="<?php echo $_GET["signo"]; ?>" />
<input type="submit" value="submit"/>
</form>
<a href = "imgupl.php?id=<?php echo $_GET["id"]; ?>" target="_blank">Click here to upload photo</a>
</td>
</table>
  <hr />
  
  
  
  
  
  
  
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
	echo '<td><img  height = "240" width = "360" src="data:image/jpeg;base64,'.base64_encode($row['photo']). ' " /></td>';
	echo '<td><img  height = "240" width = "360" src="data:image/jpeg;base64,'.base64_encode($row1['image']). ' " />'.'<hr />'.$row1['time'].'</td>';
?> 
</tr>
</table><hr />
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
