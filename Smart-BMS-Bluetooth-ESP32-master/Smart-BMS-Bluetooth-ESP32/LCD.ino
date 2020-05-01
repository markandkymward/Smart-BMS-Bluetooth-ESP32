//lcd 128 x 160 px

//#define LCDCONSTRUCTOR TFT_eSPI
//LCDCONSTRUCTOR tft = TFT_eSPI();
TFT_eSPI tft = TFT_eSPI(); 

#define SPRITECONSTRUCTOR TFT_eSprite
SPRITECONSTRUCTOR bar = TFT_eSprite(&tft);

void showInfoLcd()
{  

//    TRACE;
//
////    //tft.fillScreen(TFT_BLACK); // CLEAR makes nasty flicker, don't use
//    tft.setCursor(0, 5);
//
//    tft.setTextSize(2);
////
////    //---main voltage---
//
//    tft.setTextColor(TFT_GREEN, TFT_BLACK);
//    tft.print((float)packBasicInfo.Volts / 1000);
//
//    tft.print("V");
//    tft.println();
//
//    
//    //---single cell voltage---
//    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
//    tft.print("(");
//    tft.print((float)packCellInfo.CellMedian / 1000);
//    tft.print("V");
//    tft.print(")");
//    tft.println();
//
//    //---main current---
//    tft.setTextColor(TFT_GREENYELLOW, TFT_BLACK);
//    tft.print((float)packBasicInfo.Amps / 1000);
//    tft.print("A    ");
//    tft.println();
//
//   
//    //---ampere hours---
//    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
//    tft.print((float)packBasicInfo.CapacityRemainAh / 1000);
//    tft.print("Ah");
//    tft.println();
//
//
//    //---watts---
//    tft.setTextColor(TFT_ORANGE, TFT_BLACK);
//    tft.print(packBasicInfo.Watts);
//    tft.print("W    ");
//    tft.println();
//
//    //---battery percent---
//    tft.setTextColor(TFT_WHITE, TFT_BLACK);
//    tft.print(packBasicInfo.CapacityRemainPercent);
//    tft.print("%");
//    //tft.println();
//
//    tft.print(" ");
//    //---battery Wh---
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
//    tft.print(packBasicInfo.CapacityRemainWh);
//    tft.print("Wh");
//    tft.println();
//
//    //---temperatures---
//    tft.setTextSize(2);
//    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
//    tft.print((float)packBasicInfo.Temp1 / 10);
//    tft.print("C");
//    tft.print("    ");
//    tft.print((float)packBasicInfo.Temp2 / 10);
//    tft.print("C");
//    tft.println();

//    //------------draw little battery symbols---------
    int mid=130;
    float scale = .25;
    bar.setColorDepth(8);
    bar.createSprite(240,320);

    for (uint8_t i = 1; i <= 10; i++){
      if (i<10) 
        bar.drawChar(char(i+48), 12, i*28+15,4);
      else
        bar.drawString("10", 1, i*28+15,4);
    }
    float averageCellVolts = 0.0;
    for (uint8_t i = 1; i <=10; i++){
      averageCellVolts = packCellInfo.CellVolt[i-1] + averageCellVolts;
    }
    averageCellVolts = averageCellVolts/10;
    bar.drawString("Avg Cell:      V", 5,2,2);
    bar.drawString(String(averageCellVolts/1000,2),64,2,2);
    bar.drawString("Charge:     %", 145,2,2);
    bar.drawString(String(packBasicInfo.CapacityRemainPercent), 199, 2,2);
    bar.drawString(" -0.25           Volts      +0.25",20,22,2);
    int xoff=110;
    int yoff=25;
    bar.drawTriangle(0+xoff,10+yoff,5+xoff,0+yoff,10+xoff,10+yoff,TFT_WHITE);
    for (uint8_t i = 1; i <= 10; i++){
        float width = (packCellInfo.CellVolt[i-1]-averageCellVolts)/1000/scale * 100;
        //if (width = 0.0) width = 1.0;
        if (int(width) >= 0) 
          bar.fillRect(mid,i*28+15,int(width),20,TFT_GREEN); 
        else
          bar.fillRect(mid+int(width), i*28+15, abs(int(width)), 20, TFT_RED);  
//      tft.drawString(String((packCellInfo.CellVolt[i-1]-averageCellVolts)/1000,2),75, i*28+15,4);
    }
//    for (uint8_t i = 0; i < 10; i++)
//    {
////        //       (uint8_t origin_x, uint8_t origin_y, uint8_t width, uint8_t height, float value, float valueMin, float valueMax, LCDCONSTRUCTOR &refLCD)
//        lcdBargraphVertical(i*20+10, 0, 100, 100, packCellInfo.CellVolt[i], c_cellAbsMin, c_cellAbsMax, packCellInfo.CellColor[i], packCellInfo.CellColorDisbalance[i], bar);
//    }
//
     bar.drawLine(mid-1,28+15,mid-1,314,TFT_WHITE);
     bar.pushSprite(0, 0);
     bar.deleteSprite();

    //------------draw testing rectagle---------
    
//    tft.fillRect(0, 0, 5, 10, TFT_RED);
//    tft.fillRect(120, 21, 5, 10, TFT_GREEN);
//    tft.fillRect(120, 32, 5, 10, TFT_BLUE);
//    tft.fillRect(100, 10, 5, 10, color24to16(packCellInfo.CellColor[0]));


    //-------------print cell voltges--------
    
//    for (byte i = 1; i <= packCellInfo.NumOfCells-2; i++)
//    {
//        tft.setTextColor(TFT_LIGHTGREY, TFT_BLACK);
//        tft.print(i);
//        if (i < 10)
//        {
//            tft.print(".  ");
//        }
//        else
//        {
//            tft.print(". ");
//        }
//        tft.setTextColor(TFT_YELLOW, TFT_BLACK);
//        tft.print((float)packCellInfo.CellVolt[i - 1] / 1000);
//        tft.print("V");
//        if (i % 2 != 0)
//        {
//            tft.print("  ");
//        }
//        else
//        {
//            tft.println();
//        }
//    }

//    //----draw wifi icon----
//    // if (WiFi.status() == WL_CONNECTED)
//    // {
//    //     tft.fillRect(122, 0, 5, 5, TFT_GREEN);
//    // }
//    // else
//    // {
//    //     tft.fillRect(122, 0, 5, 5, TFT_DARKGREY);
//    // }
//
//    //-----draw progressbar-----
//
    //drawBar(3, 85, 122, 15, packBasicInfo.CapacityRemainPercent, TFT_WHITE, color24to16(getPixelColorHsv(mapHue(packBasicInfo.CapacityRemainPercent, 0, 100), 255, 255)), tft);

    //drawBar(3, 105, 122, 15, map(abs(packBasicInfo.Watts), 0, c_packMaxWatt, 0, 100), TFT_WHITE, color24to16(getPixelColorHsv(mapHue(abs(packBasicInfo.Watts), c_packMaxWatt, 0), 255, 255)), tft);

//    char unit1[] = "%";
//    bar.setColorDepth(18);
//    bar.createSprite(122, 20);
//    drawBarUnit(0, 0, 122, 20, 0, 100, packBasicInfo.CapacityRemainPercent, TFT_WHITE, color24to16(getPixelColorHsv(mapHue(packBasicInfo.CapacityRemainPercent, 0, 100), 255, 255)), unit1, bar);
//    bar.pushSprite(1, 80);
//    bar.deleteSprite();
//
//    char unit2[] = "W";
//    bar.setColorDepth(18);
//    bar.createSprite(122, 26);
//    drawBarUnit(0, 0, 122, 26, 0, c_packMaxWatt, abs(packBasicInfo.Watts), TFT_WHITE, color24to16(getPixelColorHsv(mapHue(abs(packBasicInfo.Watts), c_packMaxWatt, 0), 255, 255)), unit2, bar);
//    bar.pushSprite(1, 105);
//    bar.deleteSprite();
}

// void lcdStartNetworking()
// {

//     tft.println("looking for wifi AP");
// }

// void lcdNetworkStatus(uint8_t state)
// {
//     switch (state)
//     {
//     case 0:
//         tft.println("wifi connected");
//         tft.println(WiFi.localIP());
//         break;
//     case 1:
//         tft.println("wifi failed connect");
//     default:
//         tft.println("unkwon error");
//         break;
//     }
// }

void lcdStartup()
{
    tft.init();
    tft.setRotation(0); //
    //tft.setTextWrap(false);
    //tft.fillScreen(TFT_BLACK); // CLEAR
//
//    tft.setCursor(0,0);
//    tft.setTextSize(1);
//    tft.setTextColor(TFT_GREEN, TFT_BLACK);
}

void lcdDisconnect()
{
    
    tft.fillScreen(TFT_BLACK); // CLEAR
    tft.setCursor(3, 5);
    tft.setTextColor(TFT_RED);
    tft.setTextSize(2);
    tft.println("BMS lost");

    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(1);
    tft.println("");
    tft.println("reconnecting....");
    tft.println("(it may take a while)");
}

void lcdConnected()
{
    tft.setTextColor(TFT_GREEN);
    tft.println("connected!");
    delay(200);
    tft.fillScreen(TFT_BLACK); // CLEAR
}

void lcdConnectionFailed()
{

    commSerial.println("We have failed to connect to the server; there is nothin more we will do.");
    tft.setTextColor(TFT_RED);
    tft.println("connection failed!");
}

void lcdConnectingStatus(uint8_t state)
{
    switch (state)
    {
    case 0:
        tft.setTextColor(TFT_YELLOW);
        tft.setTextSize(1);
        tft.println("connecting to BMS...");
        break;
    case 1:
        tft.println("created client");
        break;
    case 2:
        tft.println("connected to server");
        break;
    case 3:
        tft.println("service not found");
        break;
    case 4:
        tft.println("found service");
        break;
    case 5:
        tft.println("char. not found");
        break;
    case 6:
        tft.println("char. found");
        break;
    default:
        break;
    }
}
void lcdExample()
{
}

void lcdBargraphVertical(uint8_t origin_x, uint8_t origin_y, uint8_t width, uint8_t height, uint16_t value, uint16_t valueMin, uint16_t valueMax, uint32_t insideColor, uint32_t outsideColor, SPRITECONSTRUCTOR &refLCD)
{
    const uint8_t spacing = 2;
    if (value < valueMin)
    {
        value = valueMin;
    }
    if (value > valueMax)
    {
        value = valueMax;
    }

    uint8_t box_origin_x = origin_x + spacing;
    uint8_t box_origin_y = origin_y + spacing;
    uint8_t box_width = width - spacing * 2;
    uint8_t box_min_height = 1;
    uint8_t box_max_height = height - spacing;

    uint8_t nipple_origin_x = box_origin_x;
    uint8_t nipple_origin_y = origin_y - spacing;
    uint8_t nipple_width = box_width;
    uint8_t nipple_height = spacing;

    refLCD.fillRect(box_origin_x, box_origin_y, box_width, box_max_height, TFT_BLACK); // "delete" old battery

    int16_t box_height = map(value, valueMax, valueMin, box_min_height, box_max_height);
    box_origin_y = box_origin_y + box_height;
    box_height = box_max_height - box_height - spacing;
    if (box_height < 0) //ugly hack
    {
        box_height = 0;
    }
    outsideColor = 0xFAFAFA;
    refLCD.drawRect(origin_x, origin_y, width, height, color24to16(outsideColor)); //(u8g2_uint_t x, u8g2_uint_t y, u8g2_uint_t w, u8g2_uint_t h)
    refLCD.fillRect(nipple_origin_x, nipple_origin_y, nipple_width, nipple_height, color24to16(outsideColor));

    refLCD.fillRect(box_origin_x, box_origin_y, box_width, box_height, color24to16(insideColor));
}

// void drawBar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t percent, uint16_t frameColor, uint16_t barColor, LCDCONSTRUCTOR &refLCD)
// {
//     if (true) //percent == 0)
//     {
//         refLCD.fillRoundRect(x, y, w, h, 3, TFT_BLACK);
//     }
//     uint8_t margin = 2;
//     uint16_t barHeight = h - 2 * margin;
//     uint16_t barWidth = w - 2 * margin;
//     refLCD.drawRoundRect(x, y, w, h, 3, frameColor);
//     refLCD.fillRect(x + margin, y + margin, barWidth * percent / 100.0, barHeight, barColor);
// }

void drawBar(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t valueMin, uint32_t valueMax, uint32_t value, uint16_t frameColor, uint16_t barColor, SPRITECONSTRUCTOR &refLCD)
{
    if (value < valueMin)
    {
        value = valueMin;
    }
    if (value > valueMax)
    {
        value = valueMax;
    }

    uint8_t margin = 2;
    uint16_t barHeight = h - 2 * margin;
    uint16_t barMaxWidth = w - 2 * margin;
    uint16_t barWidth = map(value, valueMin, valueMax, 0, barMaxWidth); //barMaxWidth * value / 100.0;

    refLCD.drawRoundRect(x, y, w, h, 3, frameColor); //frame

    refLCD.fillRect(x + margin, y + margin, barWidth, barHeight, barColor); // colored inside

    refLCD.fillRect(x + margin + barWidth, y + margin, barMaxWidth - barWidth, barHeight, TFT_BLACK); // inside bar,  between actual value and max
}

void drawBarUnit(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint32_t valueMin, uint32_t valueMax, uint32_t value, uint16_t frameColor, uint16_t barColor, char *unit, SPRITECONSTRUCTOR &refLCD)
{
    if (value < valueMin)
    {
        value = valueMin;
    }
    if (value > valueMax)
    {
        value = valueMax;
    }
    const uint16_t tw = 48;    //half of text width
    const uint16_t th = 8;     // half of text height
    const uint16_t border = 1; //black part of text
    const uint8_t font = 2;

    char tbuff[8];

    sprintf(tbuff, "%4d", value);
    strcat(tbuff, unit);

    drawBar(x, y, w, h, valueMin, valueMax, value, frameColor, barColor, bar); //draw only bar
    //refLCD.setTextSize(3);
    refLCD.setTextColor(TFT_BLACK);
    refLCD.drawString(tbuff, x + w / 2 - border - tw, y + h / 2 + border - th, font); //black border, drawing same text offseted by 'border' all the way round
    refLCD.drawString(tbuff, x + w / 2 - border - tw, y + h / 2 - border - th, font);
    refLCD.drawString(tbuff, x + w / 2 + border - tw, y + h / 2 - border - th, font);
    refLCD.drawString(tbuff, x + w / 2 + border - tw, y + h / 2 - border - th, font);
    refLCD.drawString(tbuff, x + w / 2 + border - tw, y + h / 2 + border - th, font);
    refLCD.drawString(tbuff, x + w / 2 + border - tw, y + h / 2 + border - th, font);
    refLCD.drawString(tbuff, x + w / 2 + border - tw, y + h / 2 + border - th, font);
    refLCD.drawString(tbuff, x + w / 2 - border - tw, y + h / 2 + border - th, font);

    refLCD.setTextColor(TFT_WHITE);
    refLCD.drawString(tbuff, x + w / 2 - tw, y + h / 2 - th, font); //finally, the white text
}
