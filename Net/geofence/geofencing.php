<?php
//avail online sig by matlab
function distance($lat1, $lon1, $lat2, $lon2, $unit) {

  $theta = $lon1 - $lon2;
  $dist = sin(deg2rad($lat1)) * sin(deg2rad($lat2)) +  cos(deg2rad($lat1)) * cos(deg2rad($lat2)) * cos(deg2rad($theta));
  $dist = acos($dist);
  $dist = rad2deg($dist);
  $miles = $dist * 60 * 1.1515;
  $unit = strtoupper($unit);

  if ($unit == "K") {
    return ($miles * 1.609344);
  } else if ($unit == "N") {
      return ($miles * 0.8684);
    } else {
        return $miles;
      }
}


//echo distance(32.9697, -96.80322, 29.46786, -98.53506, "M") . " Miles<br>";
//echo distance(77.292946, 19.111584, 77.322029, 19.147188, "K") . " Kilometers<br>";
//echo distance(32.9697, -96.80322, 29.46786, -98.53506, "N") . " Nautical Miles<br>";
echo distance(19.111584, 77.292946, 19.147188, 77.322029, "K") . " Kilometers<br>";
echo distance(19.111584, 77.292946, 19.147188, 77.322029, "K")*1000 . " + 20 or - 20 Meters<br>";
echo distance(19.111584, 77.292946, 19.112675, 77.291935, "K") . " Kilometers<br>";
echo distance(19.111584, 77.292946, 19.112675, 77.291935, "K")*1000 . " Meters<br>";
?>