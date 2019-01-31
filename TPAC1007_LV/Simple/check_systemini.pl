#!/usr/bin/perl
use strict;
use warnings;

print "Checking the system.ini...\n";

my $projectfilename = $ARGV[0];
my $srcdirname = $ARGV[1];

my $model = "";
my $line = "";
open(INFILE, $srcdirname."/template.pri") or die  "'".$srcdirname."/template.pri" . "': ". $!;
while ($line = <INFILE>)
{
	if ($line =~ /^TYPE/)
	{
		my $key;
		my @values = split('=', $line);
		$key = $values[0];
		$model = $values[1];
		# trim $key
		$key =~ s/^\s+|\s+$//g;
		# trim $model
		$model =~ s/^\s+|\s+$//g;
		# remove doublequotes from $model
		$model =~ s/(?:^|(?<=\|))"|"(?=$|\|)//g;
		last;
	}
}
close INFILE;

if ( $model eq "" )
{
	print STDERR "Warning: Cannot find variable 'TYPE' into 'template.pri'. Cannot perform the system.ini check.\n";
	exit 0;
}
#print "TYPE: " . $model . "...\n";

open(INFILE, $srcdirname."/config/system.ini") or die  "'".$srcdirname."/config/system.ini" . "': ". $!;
my $retval = 0;
my $section;
while ($line = <INFILE>)
{
	my $key = "";
	my $value = "";
	if ($line =~ /\[([A-z0-9]+)\]/)
	{
		$section = $1;
	}
	elsif ($line =~ /=/)
	{
		my @values = split('=', $line);
		$key = $values[0];
		$value = $values[1];
		$key =~ s/^\s+|\s+$//g;
		$value =~ s/^\s+|\s+$//g;
		
		if ($model eq "TP1057_01_A" || $model eq "TP1057_01_B")
		{
			# nothing to check
		}
		elsif ($model eq "TP1070_01_A" || $model eq "TP1070_01_B" || $model eq "TP1070_01_C" || $model eq "TP1070_01_D")
		{
			# nothing to check
		}
                elsif ($model eq "TPAC1007_03" || $model eq "TPAC1007_04_AA" || $model eq "TPAC1007_04_AB" || $model eq "TPAC1007_04_AC")
                {
                        if ($section eq "SERIAL_PORT_3" && $key eq "baudrate" && $value ne "225000")
                        {
                                print "Error: for product '" . $model . "' in the section '" . $section . "' the parameter '" . $key . "' must be '225000' instead of '" . $value . "'\n";
                                $retval = 1;
                        }
                }
                elsif ($model eq "TPAC1007_LV")
                {
                        if ($section eq "SERIAL_PORT_3" && $key eq "baudrate" && $value ne "38400")
                        {
                                print "Error: for product '" . $model . "' in the section '" . $section . "' the parameter '" . $key . "' must be '38400' instead of '" . $value . "'\n";
                                $retval = 1;
                        }
                }
                elsif ($model eq "TPAC1008_02_AA" || $model eq "TPAC1008_02_AB" || $model eq "TPAC1008_02_AC" || $model eq "TPAC1008_02_AD" || $model eq "TPAC1008_02_AE" || $model eq "TPAC1008_02_AF")
		{
			if ($section eq "CANOPEN_0" && $key eq "baudrate" && $value ne "125000")
			{
				print "Error: for product '" . $model . "' in the section '" . $section . "' the parameter '" . $key . "' must be '225000' instead of '" . $value . "'\n";
				$retval = 1;
			}
		}
	}
}
close INFILE;

print "Check the system.ini done.\n";
exit $retval;

