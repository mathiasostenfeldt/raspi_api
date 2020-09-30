<?php

namespace App\Http\Controllers;
use Illuminate\Support\Facades\Http;

class TemperatureController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        //
    }

    public function getTemperature()
    {
        // Use current position....
        //$long = 10.268713;
        //$lat = 55.456375;
        $command = escapeshellcmd('sudo python /var/www/html/raspi_api/app/python-scripts/gettemp.py');
        exec($command,$out,$ret);
        echo($ret);
        echo($out);
        print $ret;
        print $out;
        //return $temp;
    }
}