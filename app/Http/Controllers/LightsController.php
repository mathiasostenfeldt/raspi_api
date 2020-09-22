<?php

namespace App\Http\Controllers;

class LightsController extends Controller
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

    public function dimLight($amount)
    {
        //check state of ligth
        $isOn = true;
        if($isOn == true){
            //dimm light
            return true;
        }else{
            //couldnt dimm
            return false;
        }
    }

    public function turnOnLight()
    {
        $isOn = false;
        //check state off light
        $isOn = true;
        //try turn on
        exec('sudo python grove_led_blink.py');
        return $isOn ? true : false;
    }

    public function turnOffLight()
    {
        $isOff = false;
        //check state off light
        $isOff = true;
        //try turn on
        return $isOff ? true : false;
    }
}