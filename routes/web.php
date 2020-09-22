<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It is a breeze. Simply tell Lumen the URIs it should respond to
| and give it the Closure to call when that URI is requested.
|
*/

use App\Http\Controllers\LightsController;

$router->get('/', function () use ($router) {
    return $router->app->version();
});

$router->get('foo', function () {
    return 'Hello World';
});

$router->get('/lights/turnonlight', 'LightsController@turnOnLight');
$router->get('/lights/turnofflight', 'LightsController@turnOffLight');
$router->get('/lights/dimmlight/{$amount}', 'LightsController@dimmLight');

$router->get('temperature/gettemperature', 'TemperatureController@getTemperature'); 




