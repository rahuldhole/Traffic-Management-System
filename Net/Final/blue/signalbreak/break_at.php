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

  <h1>List of signal break from <?php if($_GET["signo"]) echo $_GET["signo"]; ?></h1>

  
<table border = '0' style = 'color : white' align = 'center'><tr style=
'background:#0193e9 ' style='font-family:Comic Sans MS' align = 'center'>
</tr>

<?php
include_once("../db.php");
//SELECT * FROM `signals_break` WHERE `signo`='IT_DEPT' order by `time`desc
$q = "SELECT * FROM signals_break WHERE signo = '".$_GET["signo"]."' order by time desc";
$result = mysqli_query($conn, $q);
//INSERT INTO `a1100935_dbms`.`login` (`mobile`, `password`) VALUES ('9545584590', 'kismat');
$row  = mysqli_fetch_array($result);
if(is_array($row)) 
							{
								foreach($result as $row)
								{
									echo"<tr style='background:silver' style='font-family:Comic Sans MS' align = 'center'>";
									//echo "<td><a href = 'defaulter.php?id=".$row['id']."&&signo=".$row['signo']."'>".$row['signo']."</a></td>"."<td>";
									echo "<td><a href = 'defaulter.php?id=".$row['id']."&&signo=".$row['signo']."'>";
									echo '<img  height = "160" width = "180" src="data:image/jpeg;base64,'.base64_encode($row['image']). ' " />';
									echo "<hr />".$row['time']."</a></td>"."<td>";
									echo"</tr>";
								}
							} else {
echo "Data not available...";
}

?>  
</table>
<br />
<a href = "break_at.php?n=<?php echo $_GET["n"]-5; ?>&signo=<?php echo $_GET["signo"]; ?>">Previous Page</a> &nbsp;&nbsp;&nbsp;&nbsp;<a href = "break_at.php?n=<?php echo $_GET["n"]+5; ?>&signo=<?php echo $_GET["signo"]; ?>">Next Page</a>

<hr />
    <div align = "center">
<a href = "defaulter.php">Click here to check defaulters</a>
</div>
  
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
