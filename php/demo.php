<?php
    $foo = null;
    if (is_array($foo) && array_key_exists('key', $foo)) {
        echo 'T'.PHP_EOL;
    } else {
        echo 'F'.PHP_EOL;
    }
    $foo = array(
        'key' => 'value',
        'bar' => 14,
    );
    echo $foo['bar'].PHP_EOL;

    define('USERID', 'userid');
    echo USERID.PHP_EOL;
