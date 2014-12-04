
void setup() {
  size(800, 600);
  frameRate(60);
  
  // lade das ganze XML
  XML siteXML = loadXML("http://api.wefeelfine.org:8080/ShowFeelings?display=xml&returnfields=%20imageid,feeling,%20sentence,posttime,postdate,posturl,gender,born,country,%20state,city,lat,lon,conditions&limit=5");
  //println(siteXML);

  // fuer jedes child eine XML objekt
  XML[] feeling = siteXML.getChildren("feeling");
  println(feeling.length);

  // die feelings am besten in ein Array speichern:
  for (int i = 0; i<feeling.length; i++) {
    println(i+ ": " + feeling[i].getString("sentence"));
  }
}

void draw() {
  background(255);
}
