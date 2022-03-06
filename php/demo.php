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

    $jsonstr = '{
      "key0": "value0",
      "key1": "value1",
      "key1": "value2"
    }';

    $foo = json_decode($jsonstr, true);
    echo $foo['key1'].PHP_EOL;

    $foo = 'master';
    $foo = sha1($foo.'tgtoken');
    echo $foo.PHP_EOL;
    $bar = sha1('tgtoken'.$foo);
    echo $bar.PHP_EOL;
