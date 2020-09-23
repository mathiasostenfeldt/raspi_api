<?php


namespace App\Http\Controllers;

use PhpGpio\Gpio;

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
        $gpio = new Gpio();
        $gpio->setup(18, 'out');
        while(true) {
            // To Switch ON the LED
            $gpio->output(18, 1);
            sleep(1);
            // To Switch OFF the LED
            $gpio->output(18, 0);
            sleep(1);
            break;
        }
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