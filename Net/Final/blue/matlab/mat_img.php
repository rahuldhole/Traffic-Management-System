<?php
if(count($_POST)>0){
		include_once("../db.php");
		print_r($_POST);
		//image_name
		if(isset($_FILES['file'])) {
        $name=$_POST['image_name'];//signal side
		$signo=$_POST['signo'];
        $fp=addslashes(file_get_contents($_FILES['file']['tmp_name'])); //will store the image to fp
        }
		$dat = "".date("Y-d-m h:i:s");
		
		mysqli_query($conn,"SET AUTOCOMMIT=0");
		mysqli_query($conn,"START TRANSACTION");

		
		$sql = "INSERT INTO signals_break VALUES('null', '{$signo}',DEFAULT,'{$fp}');";
		$a1 = mysqli_query($conn, $sql);
		 $sql = "SELECT id FROM signals_break WHERE image = '".$fp."'";
		$res = mysqli_query($conn, $sql);
		$row  = mysqli_fetch_array($res);
		$id = $row['id'];
		echo $id;
		$sql = "INSERT INTO defaulters VALUES('{$id}', DEFAULT,DEFAULT,DEFAULT,'{$_POST['image_name']}','null');";
		$a2 = mysqli_query($conn, $sql); 
		if ($a1 and $a2) {
			mysqli_query($conn,"COMMIT");
		} else {        
			mysqli_query($conn,"ROLLBACK");
		}
		
}							
/*

mysql_query("SET AUTOCOMMIT=0");
mysql_query("START TRANSACTION");

$a1 = mysql_query("INSERT INTO rarara (l_id) VALUES('1')");
$a2 = mysql_query("INSERT INTO rarara (l_id) VALUES('2')");

if ($a1 and $a2) {
    mysql_query("COMMIT");
} else {        
    mysql_query("ROLLBACK");
}
*/

?>
