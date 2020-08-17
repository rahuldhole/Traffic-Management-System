
<!-- this form is user to store images-->
<form action="index.php" method="post"  enctype="multipart/form-data">
Enter the Image Name:<input type="text" name="image_name" id="" /><br />

<input name="image" id="image" accept="image/JPEG" type="file"><br /><br />
<input type="submit" value="submit" name="submit" />
</form>
<br /><br />
<!-- this form is user to display all the images-->
<form action="index.php" method="post"  enctype="multipart/form-data">
Retrive all the images:
<input type="submit" value="submit" name="retrive" />
</form>



<?php
//THIS IS INDEX.PHP PAGE
//connect to database.db name is images
       $con = mysqli_connect("localhost", "inventme_kismat", "Kismat@30") OR DIE (mysqli_error());
        mysqli_select_db ($con,"inventme_tms") OR DIE ("Unable to select db".mysqli_error());
//to retrive send the page to another page
if(isset($_POST['retrive']))
{
    header("location:search.php");

}

//to upload
if(isset($_POST['submit']))
{
if(isset($_FILES['image'])) {
        $name=$_POST['image_name'];
        $fp=addslashes(file_get_contents($_FILES['image']['tmp_name'])); //will store the image to fp
        }
                // our sql query
                $sql = "INSERT INTO images VALUES('null', '{$name}','{$fp}','null');";
				//$sql = "UPDATE `images` SET `image` =  '".$fp."', WHERE `name` ='".$name."'";
				mysqli_query($con, $sql);// or die("Error in Query insert: ".mysqli_error()); 
} 
?>


