use 5.010;
use Moose;
use Catalyst;
use Sys::Prctl;

# Set programname
$0 = $ARGV[0];
Sys::Prctl::prctl_name($ARGV[1]);

while(1) {}

