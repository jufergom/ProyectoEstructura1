package javaapplicationtwitter;

import twitter4j.*;
import java.util.List;
import twitter4j.Query;
import twitter4j.QueryResult;
import twitter4j.StatusUpdate;
import twitter4j.Twitter;
import twitter4j.TwitterFactory;
import twitter4j.User;
import twitter4j.Status;
import twitter4j.TwitterException;
import twitter4j.conf.ConfigurationBuilder;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;
import jdk.nashorn.api.scripting.JSObject;
import sun.awt.FwDispatcher;

public class JavaApplicationTwitter {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ConfigurationBuilder cb = new ConfigurationBuilder();
        
        cb.setDebugEnabled(true);
        cb.setOAuthConsumerKey("CJnaPXYtcKwOBjIb6yAfCw0a7");
        cb.setOAuthConsumerSecret("bblOp5MFJ4BFsIBewBuXmMZiahPo0gXM4HT6Lz1ZZgMHY0lkI0");
        cb.setOAuthAccessToken("3177506198-o5rYWh6c8s1KCpx6eKhZqSwVWceAbfKcaHMTQk6");
        cb.setOAuthAccessTokenSecret("QM7ChjUxyNPJGAntMKnvBs7AxOmoGKarDtnINWFWb6QdZ");
        
        //Probando Json
        //*****************
        
        
       /* JSONArray list = new JSONArray();
        list.add("primer tag");
        list.add("segundo tag");
        
        obj.put("Tags", list);
        JSONObject inter= new JSONObject();
        */
        
       //******************
        
        int contas=0,c=1;
        JSONObject obj = new JSONObject();
        TwitterFactory tf = new TwitterFactory(cb.build());
        Twitter twitter = tf.getInstance();
        String usuario="jhair001";
        //aqui ponemos el file donde guardamos los tweets
        File file = new File("C:/Users/jufer/Documents/Proyecto/JavaApplicationTwitter/tweets.txt");
        //File json1 = new File("tweets1.json"); 
       
        //la palabra de los tweets que se quiere buscar
        File word = new File("C:/Users/jufer/Documents/Proyecto/JavaApplicationTwitter/word.txt");
        String fileWord;
        //String fileWord = JOptionPane.showInputDialog(null, "Palabra que "
                //+ "desea buscar");
        /*if (json1.exists()){
              json1 = new File("");
              for (int i = 0; i < contas; i++) {
                contas++;
            }
        }     
        */
        
        
        try {
            
            
            Scanner reader = new Scanner(word);
            file.createNewFile();
            
            fileWord = reader.nextLine(); //se lee la palabra del archivo
            
            
            FileWriter fw = new FileWriter(file);
            
            //json
            //***********
            //FileWriter file1 = new FileWriter(json1);
            
            
            //***********
            
            fw.write("");
         Query que= new Query(fileWord); //se le manda de parametro la palabra
         QueryResult result;
       
        result= twitter.search(que);
        List<Status>statuses=result.getTweets();
        User user = twitter.showUser("Jhair001");
        Status tweet = twitter.showStatus(30);    
        //twitter.sendDirectMessage("jufergom", "Julio es gay, enviado desde java prrrooo, +100 lince para mi");
        
        //System.out.println(usuario);
        
            for (Status status : statuses) {
                //System.out.println(status.getUser().getScreenName()+"<<<  >>> "+status.getText()+"<<<  >>> "+status.getUser().getTimeZone()
                        //+"<<<  >>> "+status.getUser().getName());
                fw.write(">>>"+status.getText()+">>>");
                //obj.put(status.getUser().getScreenName(), status.getText());//coloco los datos en el archivo json
            }
            
            fw.close();
            //file1.write(obj.toJSONString());
            //file1.flush();
            //file1.close();
                //System.out.println(tweet);   
           /* for (int i = 0; i < 5; i++) {
                System.out.println(user.getName()+"<<<  >>> "+user.getScreenName() +"<<<  >>> "+ user.getStatus());
            }*/
     
         
                
        } catch (TwitterException te) {
            System.out.println("Failed to search tweets: " + te.getMessage());
            System.exit(-1);
        }
        catch (IOException e) {
            
        }
        /*
       
         if (args.length < 1) {
            System.out.println("java twitter4j.examples.search.SearchTweets [jhair001]");
            System.exit(-1);
        }
        Twitter twitter = new TwitterFactory().getInstance();
        try {
            Query query = new Query(args[0]);
            QueryResult result;
            do {
                result = twitter.search(query);
                List<Status> tweets = result.getTweets();
                tweets.forEach((tweet) -> {
                    System.out.println("@" + tweet.getUser().getScreenName() + " - " + tweet.getText());
                });
            } while ((query = result.nextQuery()) != null);
            System.exit(0);
        } catch (TwitterException te) {
            System.out.println("Failed to search tweets: " + te.getMessage());
            System.exit(-1);
        }
        
    */
    }
    
}
