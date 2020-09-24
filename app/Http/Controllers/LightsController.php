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
        $command = escapeshellcmd('sudo python /var/www/html/raspi_api/app/python-scripts/turnonalllight.py');
        $output = shell_exec($command);
        echo $output;
        $isOn = true;
        //try turn on
        
        
        return $isOn ? true : false;
    }

    public function turnOffLight()
    {
        $isOff = false;
        //check state off light
        $command = escapeshellcmd('sudo python /var/www/html/raspi_api/app/python-scripts/turnoffalllight.py');
        $output = shell_exec($command);
        echo $output;
        $isOff = true;
        //try turn on
        return $isOff ? true : false;
    }
}