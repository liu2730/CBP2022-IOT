const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<style>
</style>
<body>
<div>
<canvas id="bettingarea"></canvas><br>
</div>
<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.6.0/Chart.min.js">

var myLineChart, label=0, interval;

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
  updateChart(myLineChart, "ADCValue");
}, 2000); //2000mSeconds update rate


function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("ADCValue").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}

function renderchart() {
   var ctx = document.getElementById("bettingarea").getContext('2d');
   myLineChart = new Chart(ctx, {
      type: 'line',
      data: {
         labels: ["0"],
         datasets: [{
            label: 'Crash Graph',
            data: [0],
            backgroundColor: [
               'rgba(255, 99, 132, 0.2)',
               'rgba(54, 162, 235, 0.2)',
               'rgba(255, 206, 86, 0.2)',
               'rgba(75, 192, 192, 0.2)',
               'rgba(153, 102, 255, 0.2)',
               'rgba(255, 159, 64, 0.2)'
            ],
            borderColor: [
               'rgba(255,99,132,1)',
               'rgba(54, 162, 235, 1)',
               'rgba(255, 206, 86, 1)',
               'rgba(75, 192, 192, 1)',
               'rgba(153, 102, 255, 1)',
               'rgba(255, 159, 64, 1)'
            ],
            borderWidth: 1
         }]
      },
      options: {
         scales: {
            yAxes: [{
               ticks: {
                  beginAtZero: True
               }
            }]
         }
      }
   });
}

function updateChart(chart, ADCVal) {
   chart.data.labels = [];
   chart.data.datasets[0].data = [];
   label++;
   //update chart
   chart.data.labels.push(label.toString());
   chart.data.datasets[0].data.push(+ADCVal.toFixed(2));
   chart.update();
}

window.onload = renderchart();


</script>
</body>
</html>
)=====";