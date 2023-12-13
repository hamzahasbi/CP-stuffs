<?php

$handle = fopen("../../io/input.in", "r");
if ($handle) {
  $is_grid = FALSE;
  $grid = [];
  $answer = 0;
  while (!feof($handle)) {
    $line = (string) trim(fgets($handle));
    $is_grid = empty($line);
    // echo $line;
    if ($is_grid) {
      $n = count($grid);
      $m = strlen(trim($grid[0]));
      // print_r ($grid);
      $rows = puzzle_solver($grid, $n, $m) * 100;
      $flipped_grid = transversal($grid, $n, $m);
      $columns = puzzle_solver($flipped_grid, $m, $n);
      // print($rows . "\n" . $columns . "\n");
      $answer += $columns + $rows;
      $grid = [];
    }
    else {
      array_push($grid, trim($line));
    }
  }
  print($answer);
  fclose($handle);
}


function puzzle_solver(array $grid, int $n, int $m) : int{
  for ($i = 0; $i < $n - 1; $i += 1) {
    $left = $i;
    $right = $i + 1;
    $f = TRUE;
    $diff_one = 0;
    while ($left >= 0 && $right < $n) {
      if ($grid[$left] !== $grid[$right]) {
        if (compare($grid[$left], $grid[$right]) === 1) {
          $diff_one++;
        }
        else {
          $f = FALSE;
          break;
        }
      }

      $left--;
      $right++;
    }
    if ($f && $diff_one == 1) {
      return $i + 1;
    }
  }
  return 0;
}

function transversal(array $grid, int $n, int $m) :array {
  $render = [];
  for ($j = 0; $j < $m; $j += 1) {
    $col = "";
    for ($i = 0; $i < $n; $i += 1) {
      $col .= $grid[$i][$j];
    }
    if (!empty($col)) {
      $render[] = $col;
    }
  }
  return $render;
}

function compare(string $a, string $b) : int{
  $diff = 0;
  for ($i = 0; $i < strlen($a); $i++) {
    if ($a[$i] !== $b[$i]) $diff++;
  }
  return $diff;
}
