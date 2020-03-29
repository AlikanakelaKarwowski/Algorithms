public static void main(String[] args) {
   ConvexHull_GUI CH = new ConvexHull_GUI();
   int f = Integer.parseInt(args[0]);
   boolean generateData =  (f==1);
   if (generateData){}
   else {
      //visulizing the points and convex hull
      String dataFile = args[1];
      String hullFile = args[2] + args[1];
