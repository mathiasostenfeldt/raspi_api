<?php


namespace App\Http\Controllers;

use PiPHP\GPIO\GPIO;
use PiPHP\GPIO\Pin\PinInterface;

class LightsController extends Controller
{
    
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        
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
        
        $gpio = new GPIO();
        
        $pin = $gpio->getOutputPin(4);
        return $pin;
        $pin->setValue(PinInterface::VALUE_HIGH);
        
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