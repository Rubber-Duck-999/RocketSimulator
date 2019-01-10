using System;
using System.IO;
using System.Diagnostics;
using System.Net.Sockets;
using System.Threading;

class Tester
{
	const string IP_Address = "127.0.0.1";
	// Host IP address variable

	static void Main(string[] args)
	{
		bool noIssueLoop = false;
		while(noIssueLoop == false)
		{
			// Main loop that won't exit
			bool noSocketIssueLoop = false;
			Console.WriteLine ("Program Starting");
			// Program start up
            TcpClient client_socket = new TcpClient();
		    SetUp(client_socket);
			// Client Socket begin, checks whether the connection has been made
			const int maxLengthArray = 1;
	        string[][] arrayData = new string[7][];
	        const string stringMessage = "Array data value is = ";
	        string stringValue = "0";
			// Creation of the arrays necessary for assignment
		    while(noSocketIssueLoop == false)
		    {
				// Loop for assigning array values
			    for (int i = 0; i < maxLengthArray; i++)
			    {
				    try
				    {
						// Try block for System IO exception which is 
						// comms are made and then disconnected
                       arrayData[i] = new string[maxLengthArray];
				       stringValue = requestData(client_socket);
					   if (stringValue.StartsWith("M"))
					   {
                           arrayData[i][0] = stringValue;
						   // Checks whether the message starts with the needed prefix from the host
					   }
					   else
					   {
						   Console.WriteLine("No Data Received");					   
						   // Will not assign the data to the array unless it had the correct prefix
					   }
                       Console.WriteLine("{0} {1}", stringMessage, arrayData[i][0]);	
				       // Debug line
					   Thread.Sleep(2000);
				    }
				    catch(System.IO.IOException)
			        {
				        Console.WriteLine($"Lost connection to sockets, Retrying....");
						noSocketIssueLoop = true;
						// Restarts the loop for setting of a connection
				    }
			    }
		    }
		}
	}

	public static void SetUp(TcpClient client_socket)
	{
        Console.WriteLine("Trying to connect to python process");
        bool am_connected = false;
        while(!am_connected)
        {
		    try
		    {
		        client_socket.Connect (IP_Address, 61377);
                am_connected = true;
				// Starts the connection
            }
            catch(System.Net.Sockets.SocketException)
            {
		        Console.WriteLine($"Can't connect. Retrying..");
				Thread.Sleep(500);
				// If connection can't be made just retry
            }
        }
	}
	
	private static string requestData(TcpClient client_socket)
	{
		const string str = "Msg request";
		NetworkStream server_stream = client_socket.GetStream ();
		// Fires outgoing msg string
		byte[] out_stream = System.Text.Encoding.ASCII.GetBytes (str);
		// Encodes it in ASCII 
		server_stream.Write (out_stream, 0, out_stream.Length);
		server_stream.Flush ();
		// Wait for response
		byte[] in_stream = new byte[26];
		// Sets byte array to max size of 26 bytes
		server_stream.Read (in_stream, 0, 26);
		string return_data = System.Text.Encoding.ASCII.GetString (in_stream);
		return return_data;
	}
}
