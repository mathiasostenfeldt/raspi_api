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
        $response = Http::get('http://fcc-weather-api.glitch.me/api/current?lon=10.268713&lat=55.456375');
        $result = json_decode($response);
        $temp = $response['main']['temp'];
        return $temp;
    }
}