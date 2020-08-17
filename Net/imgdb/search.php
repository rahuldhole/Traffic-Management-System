<table border = "1">
<tr>
<?php
//SEARCH.PHP PAGE
    //connect to database.db name = images
        $con = mysqli_connect("localhost", "inventme_kismat", "Kismat@30") OR DIE (mysqli_error());
        mysqli_select_db ($con, "inventme_tms") OR DIE ("Unable to select db".mysqli_error());
//display all the image present in the database

        $msg="";
        $sql="select * from images";
		$res = 0;
		$res=mysqli_query($con,$sql);
        if($res)
        {
            
            while($row=mysqli_fetch_array($res))
            {
                    $id=$row['id'];
                    $name=$row['name'];
                    $image=$row['image'];
                  $msg.= '<td><img  height = "150" width = "200" src="data:image/jpeg;base64,'.base64_encode($row['image']). ' " /> <hr />'.$row['name'].'</td>';
            }
        }
        else
            $msg.="Query failed";
?>


<?php
echo $msg;
?>
</tr>
</table>