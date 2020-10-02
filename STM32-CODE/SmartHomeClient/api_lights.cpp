#define MBED_CONF_MBED_TRACE_ENABLE 1

#include "https_request.h"
#include "mbed_trace.h"
#include "cert.h"
#include "serial_tools.h"
#include "string.h"

/*
Gets all rooms and supposed to loop all in gui
string* getAllRoomsWithLight(NetworkInterface* network) {
        
    mbed_trace_init();
    {
        
        printf("\n----- HTTPS GET request -----\n");

        HttpsRequest* get_req = new HttpsRequest(network, SSL_CA_PEM, HTTP_GET, "https://partitive-lionfish-7270.dataplicity.io/lights/getallroomswithlight");

        HttpResponse* get_res = get_req->send();
        if (!get_res) {
            printf("HttpRequest failed (error code %d)\n", get_req->get_error());
        }
        printf("\n----- HTTPS GET response -----\n");
        dump_response(get_res);

        delete get_req;
    }
    
}
*/

// GET request to https://partitive-lionfish-7270.dataplicity.io/lights/turnonlights
void turnOnAllLight(NetworkInterface* network) {
        
    mbed_trace_init();
    {
        printf("\n----- HTTPS GET request -----\n");

        HttpsRequest* get_req = new HttpsRequest(network, SSL_CA_PEM, HTTP_GET, "https://partitive-lionfish-7270.dataplicity.io/lights/turnonlight");

        HttpResponse* get_res = get_req->send();
        if (!get_res) {
            printf("HttpRequest failed (error code %d)\n", get_req->get_error());
        }
        printf("\n----- HTTPS GET response -----\n");
        dump_response(get_res);

        delete get_req;
    }
    
}

void turnOffAllLight(NetworkInterface* network) {
        
    mbed_trace_init();
    {
        printf("\n----- HTTPS GET request -----\n");

        HttpsRequest* get_req = new HttpsRequest(network, SSL_CA_PEM, HTTP_GET, "https://partitive-lionfish-7270.dataplicity.io/lights/turnofflight");

        HttpResponse* get_res = get_req->send();
        if (!get_res) {
            printf("HttpRequest failed (error code %d)\n", get_req->get_error());
        }
        printf("\n----- HTTPS GET response -----\n");
        dump_response(get_res);

        delete get_req;
    }
    
}

void turnOnInRoom(NetworkInterface* network, int roomId) {
    
        const char * body[] = {"{\"room\":\"2\"}"};
    
        if(roomId == 2){
            strcpy(body, "{\"room\":\"2\"}");
        }
        if(roomId == 3){
            strcpy(body, "{\"room\":\"3\"}");
        }
        if(roomId == 4){
            strcpy(body, "{\"room\":\"4\"}");
        }
    mbed_trace_init();
    {
        printf("\n----- HTTPS POST request -----\n");

        HttpsRequest* post_req = new HttpsRequest(network, SSL_CA_PEM, HTTP_POST, "https://partitive-lionfish-7270.dataplicity.io/lights/turnoninroom");
        post_req->set_header("Content-Type", "application/json");
        
        HttpResponse* post_res = post_req->send(body, strlen(body));
        if (!post_res) {
            printf("HttpRequest failed (error code %d)\n", post_req->get_error());
        }
        printf("\n----- HTTPS GET response -----\n");
        dump_response(post_res);

        delete post_req;
    }
    
}

void turnOffInRoom(NetworkInterface* network, int roomId) {
    
        if(roomId == 2){
            const char body[] = "{\"room\":\"2\"}";    
        }
        if(roomId == 3){
            const char body[] = "{\"room\":\"3\"}";    
        }
        if(roomId == 4){
            const char body[] = "{\"room\":\"4\"}";    
        }
    mbed_trace_init();
    {
        printf("\n----- HTTPS POST request -----\n");

        HttpsRequest* post_req = new HttpsRequest(network, SSL_CA_PEM, HTTP_POST, "https://partitive-lionfish-7270.dataplicity.io/lights/turnoffinroom");
        post_req->set_header("Content-Type", "application/json");
        
        if(roomId == 2){
            body[] = "{\"room\":\"2\"}";    
        }
        if(roomId == 3){
            body[] = "{\"room\":\"3\"}";    
        }
        if(roomId == 4){
            body[] = "{\"room\":\"4\"}";    
        }
        
        

        HttpResponse* post_res = post_req->send(body, strlen(body));
        if (!post_res) {
            printf("HttpRequest failed (error code %d)\n", post_req->get_error());
        }
        printf("\n----- HTTPS GET response -----\n");
        dump_response(post_res);

        delete post_req;
    }
    
}

