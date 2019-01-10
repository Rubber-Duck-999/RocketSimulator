package com;
//
//
//import java.io.*;
//import java.net.*;
//
//public class GUI 
//{
//    @SuppressWarnings("SleepWhileInLoop")
//    public static void main(String args[]) throws Exception 
//    {
//        String clientSentence;
//        String capitalizedSentence;
//        ServerSocket welcomeSocket = new ServerSocket(10000);
//        Socket connectionSocket = welcomeSocket.accept();
//        BufferedReader inFromClient = new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
//        DataOutputStream outToClient = new DataOutputStream(connectionSocket.getOutputStream());
//        while(true) 
//        {
//
//            //clientSentence = inFromClient.readLine();
//            //capitalizedSentence = clientSentence.toUpperCase() + '\n';
//            //System.out.print(capitalizedSentence);
//            outToClient.writeBytes(" M8");
//            Thread.sleep(500);
//        }
//    }  
//}

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.Scanner;

public class GUI 
{
    public static void main(String[] args) throws Exception 
    {
        //System.out.println("Enter the IP address of a machine running the capitalize server:");
        //String serverAddress = new Scanner(System.in).nextLine();
        Socket socket = new Socket("127.0.0.1", 61377);

        // Streams for conversing with server
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        // Consume and display welcome message from the server
        System.out.println("Start: " + in.readLine());

        Scanner scanner = new Scanner(System.in);
        while (true) 
        {
        	//System.out.println("Message from socket: " + in.readLine());
            System.out.println("\nEnter a string to send to the server (empty to quit):");
            String message = scanner.nextLine();
            if (message == null || message.isEmpty()) 
            {
               break;
            }
            out.println(message);
            System.out.println(in.readLine());
        }
       }
    
}