#include <furi.h>
#include <furi_hal_usb.h>
#include <furi_hal_usb_cdc.h>

// Send data to usb-c port
void usb_push(uint8_t * data, int delay)
{
    // Configure Flipper as a usb cdc device
    furi_hal_usb_set_config(&usb_cdc_single, NULL);

    // CDC interface 0
    furi_hal_cdc_send(0, data, sizeof(data));
    furi_delay_ms(delay);
}

// restore usb port
// You must call this if you want to use usb-c without rebooting your flipper on app close
void usb_free()
{
    // Release usb and restore normal usb state
    furi_hal_usb_set_config(NULL, NULL);
}
