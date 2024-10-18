#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) 
: capacity_( capacity ),pushed_(0),popped_( 0 ), has_error_( false ), is_closed_( false ), data_()
{}
uint64_t ByteStream::StringQueue::size() const
{
  return data_.size() - popped_;
}
void ByteStream::StringQueue::push( char c )
{
  data_.push_back( c );
}
uint64_t ByteStream::StringQueue::pop( uint64_t len)
{
  const uint64_t bytes_to_pop = std::min( len, data_.size() - popped_ );
  popped_ += bytes_to_pop;

  if(popped_ >= data_.size()/2){ //节省内存
    data_ = data_.substr(popped_);
    popped_ = 0;
  }
  return bytes_to_pop;
}
std::string_view ByteStream::StringQueue::peek() const
{
  return std::string_view { data_ }.substr( popped_ );
}
bool Writer::is_closed() const
{
  // Your code here.
  return is_closed_;
}

void Writer::push( string data )
{
  // Your code here.
  for ( auto c : data ) {
    if ( data_.size() >= capacity_ ) {
      break;
    }
    data_.push( c );
    ++pushed_;
  }
  return;
}

void Writer::close()
{
  // Your code here.
  is_closed_ = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - data_.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return pushed_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return is_closed_ && data_.size()==0;
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return popped_;
}

string_view Reader::peek() const
{
  // Your code here.
  return data_.peek();
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  popped_ += data_.pop(len);
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return data_.size();
}
