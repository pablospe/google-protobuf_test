// 
//  Example of google protobuf
//    https://code.google.com/p/protobuf/
// 

#include <iostream>
#include <fstream>
#include <string>

#include "test.pb.h"

using namespace std;

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  // write
  Person person;
  person.set_id(123);
  person.set_name("Bob");
  person.set_email("bob@example.com");

  fstream out("person.pb", ios::out | ios::binary | ios::trunc);
  person.SerializeToOstream(&out);
  out.close();
  
  // read
//   Person person;
  fstream in("person.pb", ios::in | ios::binary);
  if (!person.ParseFromIstream(&in)) {
    cerr << "Failed to parse person.pb." << endl;
    exit(1);
  }

  cout << "ID: " << person.id() << endl;
  cout << "name: " << person.name() << endl;
  if (person.has_email()) {
    cout << "e-mail: " << person.email() << endl;
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}