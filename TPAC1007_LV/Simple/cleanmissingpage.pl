#!/usr/bin/perl
use strict;
use warnings;

# open project file 
# check the page#.ui presence for each page#.cpp and page#.h pages
# if some mismatch:
#    check if physically exists into the file system
#    clean the pro file 
#    check the pages.h file and pages.cpp file and clean it

print "Checking for files mismatch...\n";

my $projectfilename = $ARGV[0];
my $srcdirname = $ARGV[1];

open(INFILE, $projectfilename) or die $!;
my $line;
my @list= "";
foreach $line (<INFILE>)
{
	chomp($line);
	$line =~ s/\\//g;
	$line =~ s/^\s+//;
	$line =~ s/\s+$//;	
	if ($line =~ /page/)
	{
		push(@list,$line);
	}
}
close INFILE;
my $last = "";
my $remove;
my $var;
foreach $var (sort @list)
{
	(my $without_extension = $var) =~ s/\.[^.]+$//;
	if (($last cmp $without_extension) != 0)
	{
		$last = $without_extension;
		if(grep( /^$without_extension.ui$/, @list ) == 0 || grep( /^$without_extension.h$/, @list ) == 0 ||  grep( /^$without_extension.cpp$/, @list ) == 0)
		{
			if (grep( /^$without_extension.ui$/, @list ) == 0)
			{
				if ( -e $without_extension . ".ui" ) 
				{
					$remove = 0;
				}
				else
				{
					$remove = 1;
				}
			}
			else
			{
				print "  Removing from the project '" . $without_extension . ".ui'\n";
				filter($without_extension);
				if ($remove)
				{
					print "  Removing from the filesystem '" . $without_extension . ".ui'\n";
					unlink( $without_extension . ".ui" );
				}
			}

			if (grep( /^$without_extension.h$/, @list ) == 0)
			{
				if ( -e $without_extension . ".h" ) 
				{
					$remove = 0;
				}
				else
				{
					$remove = 1;
				}
			}
			else
			{
				print "  Removing from the project '" . $without_extension . ".h'\n";
				filter($without_extension);
				if ($remove)
				{
					print "  Removing from the filesystem '" . $srcdirname . "/" . $without_extension . ".h'\n";
					unlink( $srcdirname . "/" . $without_extension . ".h" );
				}
			}

			if (grep( /^$without_extension.cpp$/, @list ) == 0)
			{
				if ( -e $without_extension . ".cpp" ) 
				{
					$remove = 0;
				}
				else
				{
					$remove = 1;
				}
			}
			else
			{
				print "  Removing from the project '" . $without_extension . ".cpp'\n";
				filter($without_extension);
				if ($remove)
				{
					print "  Removing from the filesystem '" . $srcdirname . "/" . $without_extension . ".cpp'\n";
					unlink( $srcdirname . "/" . $without_extension . ".cpp" );
				}
			}
		}
	}
}
print "Check for files mismatch done.\n";

print "Check for remove the not existing trend file...\n";
# if the trend file listed into the template.pri file is not existing into the file system, remove it
my $dump = 0;
my @filedata;
open(INFILE, $srcdirname . "/template.pri") or die $!;
foreach $line (<INFILE>)
{
	chomp($line);
	if ($line =~ /customtrend.files/)
	{
		my @trend_file_list = "";
		my @new_trend_file_list = "";
		my $filename = "";
		@trend_file_list = split('=', $line);
		@trend_file_list = split(' ', $trend_file_list[1]);
		foreach $filename (@trend_file_list)
		{
			if ( -e $srcdirname . "/" . $filename )
			{
				print "Adding not existing trend '" . $filename . "'.\n";
				push(@new_trend_file_list, $filename);
			}
			else
			{
				print "Removing not existing trend '" . $filename . "'.\n";
				$dump = 1;
			}
		}
		if ($dump == 0)
		{
			last;
		}
		$line = "customtrend.files = " . join(" ", @new_trend_file_list);
	}
	push(@filedata,$line);
}
close INFILE;

if ($dump == 1)
{
	open FILE, ">", $srcdirname . "/template.pri" or die $!;
	foreach $line (@filedata)
	{
		print FILE $line . "\n";
	}
	close FILE;
}

print "Check for remove the not existing trend file done.\n";

sub filter
{
	my ($file) = @_;
	my $ClassiIndex = "";

	open FILE, "<", $srcdirname . "/pages.h" or die $!;
	open TMP, "+>", undef or die $!;

	while (<FILE>) {
		if ($_ !~/#include \"$file.h/)
		{
			print TMP $_;
		}
	}
	close FILE;
	open FILE, ">", $srcdirname . "/pages.h" or die $!;

	# Move to the beginning of file
	seek(TMP,0,0);
	# Read contents of the anonymous file
	while (<TMP>) {
		print FILE $_;
	}
	close TMP;
	close FILE;

	open FILE, "<", $srcdirname . "/pages.cpp" or die $!;
	open TMP, "+>", undef or die $!;
	$ClassiIndex = $file;
	$ClassiIndex =~ s/page//;

	my $stop = 0;
	while (<FILE>) {
		if ($_ =~/<< \"page$ClassiIndex\"/)
		{
			next;
		}
		if ($_ =~/case 0x$ClassiIndex:/)
		{
			$stop = 1;
		}
		if ($stop == 0)
		{
			print TMP $_;
		}
		if ($stop == 1 && $_ =~/break;/)
		{
			$stop = 0;
		}
	}
	close FILE;
	open FILE, ">", $srcdirname . "/pages.cpp" or die $!;

	# Move to the beginning of file
	seek(TMP,0,0);
	# Read contents of the anonymous file
	while (<TMP>) {
		print FILE $_;
	}
	close TMP;
	close FILE;

	open FILE, "<", $projectfilename or die $!;
	open TMP, "+>", undef or die $!;

	while (<FILE>) {
		if ($_ !~/$file.h/ && $_ !~/$file.cpp/ && $_ !~/$file.ui/)
		{
			print TMP $_;
		}
		elsif ($_ !~/\\/ )
		{
			print TMP "\n";
		}
	}
	close FILE;
	open FILE, ">", $projectfilename or die $!;

	# Move to the beginning of file
	seek(TMP,0,0);
	# Read contents of the anonymous file
	while (<TMP>) {
		print FILE $_;
	}
	close TMP;
	close FILE;

}
