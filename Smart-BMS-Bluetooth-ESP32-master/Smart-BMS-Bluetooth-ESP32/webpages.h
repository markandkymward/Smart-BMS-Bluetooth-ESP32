const char FIRMWARE_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
 <form method='POST' action='/firmwareupdate' enctype='multipart/form-data' id='upload_form'>
   <input type='file' name='update'>
        <input type='submit' value='upload & update'>
    </form>
</body>
</html>
)=====";

const char INDEX_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<style>
    .card {
        max-width: 400px;
        min-height: 250px;
        background: #02b875;
        padding: 30px;
        box-sizing: border-box;
        color: #FFF;
        margin: 20px;
        box-shadow: 0px 2px 18px -4px rgba(0, 0, 0, 0.75);
    }
</style>

<body>

    <div class="card">
        <h4>Smart BMS monitor</h4><br>
        <h1>Sensor data:</h1><br>
        <span id="data">0</span>V
        <h1>Vyliz mi prdel</h1><br>
        
        <br><a href="/firmware">Update firmware</a>
    </div>
    <script>

        setInterval(function () {
            // Call a function repetatively with 2 Second interval
            getData();
        }, 2000); //2000mSeconds update rate

        function getData() {
            var xhttp = new XMLHttpRequest();
            xhttp.onreadystatechange = function () {
                if (this.readyState == 4 && this.status == 200) {
                    document.getElementById("data").innerHTML =
                        this.responseText;
                }
            };
            xhttp.open("GET", "getdata", true);
            xhttp.send();
        }
    </script>
</body>

</html>



)=====";