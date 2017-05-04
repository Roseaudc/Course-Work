<?php
include "menu.php";
?>
<table border=1>
<tr>
<th>Player</th>
<th>Coach</th>
</tr>
<?php
include "dbconnect.php";
$sql = "SELECT * FROM coachPlayer order by coachname, playername";

$result = myquery($mysqli,$sql);

while($row = $result->fetch_assoc()) {
  echo "<tr>";
  echo '<td>' . $row['playername'] . '</td>';
  echo '<td>' . $row['coachname'] . '</td>';
  echo "</tr>";
}
?>
</table>
