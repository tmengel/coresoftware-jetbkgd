#include "TH2INTT.h"

using namespace std;

TH2INTT::TH2INTT() : TH2Poly()
{
  TH2Poly::Initialize(-23, 23., -10., 10., 25, 25);
  TH2Poly::SetStats(0);
  TH2INTT::fill_ladder_pos_map();
  TH2INTT::fill_ladder_line();
  TH2INTT::fill_ladder_toinfo_map_bin();
  
  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B0L0S"].size(); i++) { 
    px={ladder_pos_map["B0L0S"][i].x1, ladder_pos_map["B0L0S"][i].x2, ladder_pos_map["B0L0S"][i].x3, ladder_pos_map["B0L0S"][i].x4};
    py={ladder_pos_map["B0L0S"][i].y1, ladder_pos_map["B0L0S"][i].y2, ladder_pos_map["B0L0S"][i].y3, ladder_pos_map["B0L0S"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B0L1S"].size(); i++) { 
    px={ladder_pos_map["B0L1S"][i].x1, ladder_pos_map["B0L1S"][i].x2, ladder_pos_map["B0L1S"][i].x3, ladder_pos_map["B0L1S"][i].x4};
    py={ladder_pos_map["B0L1S"][i].y1, ladder_pos_map["B0L1S"][i].y2, ladder_pos_map["B0L1S"][i].y3, ladder_pos_map["B0L1S"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B1L0S"].size(); i++) { 
    px={ladder_pos_map["B1L0S"][i].x1, ladder_pos_map["B1L0S"][i].x2, ladder_pos_map["B1L0S"][i].x3, ladder_pos_map["B1L0S"][i].x4};
    py={ladder_pos_map["B1L0S"][i].y1, ladder_pos_map["B1L0S"][i].y2, ladder_pos_map["B1L0S"][i].y3, ladder_pos_map["B1L0S"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B1L1S"].size(); i++) { 
    px={ladder_pos_map["B1L1S"][i].x1, ladder_pos_map["B1L1S"][i].x2, ladder_pos_map["B1L1S"][i].x3, ladder_pos_map["B1L1S"][i].x4};
    py={ladder_pos_map["B1L1S"][i].y1, ladder_pos_map["B1L1S"][i].y2, ladder_pos_map["B1L1S"][i].y3, ladder_pos_map["B1L1S"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }



  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B0L0N"].size(); i++) { 
    px={ladder_pos_map["B0L0N"][i].x1, ladder_pos_map["B0L0N"][i].x2, ladder_pos_map["B0L0N"][i].x3, ladder_pos_map["B0L0N"][i].x4};
    py={ladder_pos_map["B0L0N"][i].y1, ladder_pos_map["B0L0N"][i].y2, ladder_pos_map["B0L0N"][i].y3, ladder_pos_map["B0L0N"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B0L1N"].size(); i++) { 
    px={ladder_pos_map["B0L1N"][i].x1, ladder_pos_map["B0L1N"][i].x2, ladder_pos_map["B0L1N"][i].x3, ladder_pos_map["B0L1N"][i].x4};
    py={ladder_pos_map["B0L1N"][i].y1, ladder_pos_map["B0L1N"][i].y2, ladder_pos_map["B0L1N"][i].y3, ladder_pos_map["B0L1N"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B1L0N"].size(); i++) { 
    px={ladder_pos_map["B1L0N"][i].x1, ladder_pos_map["B1L0N"][i].x2, ladder_pos_map["B1L0N"][i].x3, ladder_pos_map["B1L0N"][i].x4};
    py={ladder_pos_map["B1L0N"][i].y1, ladder_pos_map["B1L0N"][i].y2, ladder_pos_map["B1L0N"][i].y3, ladder_pos_map["B1L0N"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

  // note : set the bin shape
  for (int i = 0; i < ladder_pos_map["B1L1N"].size(); i++) { 
    px={ladder_pos_map["B1L1N"][i].x1, ladder_pos_map["B1L1N"][i].x2, ladder_pos_map["B1L1N"][i].x3, ladder_pos_map["B1L1N"][i].x4};
    py={ladder_pos_map["B1L1N"][i].y1, ladder_pos_map["B1L1N"][i].y2, ladder_pos_map["B1L1N"][i].y3, ladder_pos_map["B1L1N"][i].y4};
    TH2Poly::AddBin(4, &px[0], &py[0]); 
  }

};
        
void TH2INTT::Draw( Option_t* option ) {
  TH2Poly::Draw(option); // note : Call the base class Draw() function
  
  TLatex *side_text = new TLatex();
  // side_text -> SetNDC();
  side_text -> SetTextSize(0.06);
  side_text -> SetTextAlign(21);
  
  double text_offset = 2.5;
  
  side_text -> DrawLatex(-10, 8, "South" );
  side_text -> DrawLatex(10, 8, "North" );

  TArrow *arx = new TArrow(-1.5,-8,1.5,-8,0.015,"|>");
  arx->SetAngle(40);
  arx->SetLineWidth(2);
  arx->Draw("");

  TArrow *ary = new TArrow(-1.5,-8,-1.5,-5,0.015,"|>");
  ary->SetAngle(40);
  ary->SetLineWidth(2);
  ary->Draw("");

  TLatex *coord_text = new TLatex();
  coord_text -> SetTextSize(0.05);
  coord_text -> SetTextAlign(21);
  coord_text -> DrawLatex(2, -8.5, "X");
  coord_text -> DrawLatex(-1.5, -4.5, "Y");
  coord_text -> DrawLatex(1, -6, "#odot Z");

  TLatex *note_text = new TLatex();
  note_text -> SetTextSize(0.035);
  note_text -> SetTextAlign(32);
  note_text -> DrawLatex(22, -9, "View from North to South");

  // side_text -> DrawLatex(0.285, 0.83, "South" );
  // side_text -> DrawLatex(0.64, 0.83, "North" );

  // note : Draw the line
  for (int i = 0; i < ladder_line.size(); i++)
    {
      ladder_line[i] -> Draw("lsame");
    }
}

void TH2INTT::fill_ladder_pos_map(){

  vector<ladder_pos> temp_vec; temp_vec.clear();
    
  // note : B0L0S
  for (int i = 0; i <12; i++)
    {
      temp_vec.push_back(
			 {
			   B0L0_12_r * cos((B0L0_point1_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + south_x_offset,
			   B0L0_12_r * sin((B0L0_point1_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
			   B0L0_12_r * cos((B0L0_point2_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + south_x_offset,
			   B0L0_12_r * sin((B0L0_point2_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
			   B0L0_34_r * cos((B0L0_point3_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + south_x_offset,
			   B0L0_34_r * sin((B0L0_point3_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
			   B0L0_34_r * cos((B0L0_point4_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + south_x_offset,
			   B0L0_34_r * sin((B0L0_point4_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi()))
			 });
    }
  ladder_pos_map["B0L0S"] = temp_vec; temp_vec.clear();

  // note : B0L1S
  for (int i = 0; i <12; i++)
    {
      temp_vec.push_back({
	  B0L1_12_r * cos((B0L1_point1_initial - i * 30) / (180./TMath::Pi())) + south_x_offset, B0L1_12_r * sin((B0L1_point1_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_12_r * cos((B0L1_point2_initial - i * 30) / (180./TMath::Pi())) + south_x_offset, B0L1_12_r * sin((B0L1_point2_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_34_r * cos((B0L1_point3_initial - i * 30) / (180./TMath::Pi())) + south_x_offset, B0L1_34_r * sin((B0L1_point3_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_34_r * cos((B0L1_point4_initial - i * 30) / (180./TMath::Pi())) + south_x_offset, B0L1_34_r * sin((B0L1_point4_initial - i * 30) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B0L1S"] = temp_vec; temp_vec.clear();

  // note : B1L0S
  for (int i = 0; i <16; i++)
    {
      temp_vec.push_back({
	  B1L0_12_r * cos((B1L0_point1_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + south_x_offset, B1L0_12_r * sin((B1L0_point1_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_12_r * cos((B1L0_point2_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + south_x_offset, B1L0_12_r * sin((B1L0_point2_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_34_r * cos((B1L0_point3_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + south_x_offset, B1L0_34_r * sin((B1L0_point3_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_34_r * cos((B1L0_point4_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + south_x_offset, B1L0_34_r * sin((B1L0_point4_initial - i * 22.5 - 22.5) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B1L0S"] = temp_vec; temp_vec.clear();

  // note : B1L1S
  for (int i = 0; i <16; i++)
    {
      temp_vec.push_back({
	  B1L1_12_r * cos((B1L1_point1_initial - i * 22.5) / (180./TMath::Pi())) + south_x_offset, B1L1_12_r * sin((B1L1_point1_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_12_r * cos((B1L1_point2_initial - i * 22.5) / (180./TMath::Pi())) + south_x_offset, B1L1_12_r * sin((B1L1_point2_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_34_r * cos((B1L1_point3_initial - i * 22.5) / (180./TMath::Pi())) + south_x_offset, B1L1_34_r * sin((B1L1_point3_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_34_r * cos((B1L1_point4_initial - i * 22.5) / (180./TMath::Pi())) + south_x_offset, B1L1_34_r * sin((B1L1_point4_initial - i * 22.5) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B1L1S"] = temp_vec; temp_vec.clear();

  // note : B0L0N
  for (int i = 0; i <12; i++)
    {
      temp_vec.push_back({
	  B0L0_12_r * cos((B0L0_point1_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + north_x_offset, B0L0_12_r * sin((B0L0_point1_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
	  B0L0_12_r * cos((B0L0_point2_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + north_x_offset, B0L0_12_r * sin((B0L0_point2_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
	  B0L0_34_r * cos((B0L0_point3_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + north_x_offset, B0L0_34_r * sin((B0L0_point3_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())),
	  B0L0_34_r * cos((B0L0_point4_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi())) + north_x_offset, B0L0_34_r * sin((B0L0_point4_initial - 5 * 30 - i * 30 - 30) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B0L0N"] = temp_vec; temp_vec.clear();

  // note : B0L1N
  for (int i = 0; i <12; i++)
    {
      temp_vec.push_back({
	  B0L1_12_r * cos((B0L1_point1_initial - i * 30) / (180./TMath::Pi())) + north_x_offset, B0L1_12_r * sin((B0L1_point1_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_12_r * cos((B0L1_point2_initial - i * 30) / (180./TMath::Pi())) + north_x_offset, B0L1_12_r * sin((B0L1_point2_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_34_r * cos((B0L1_point3_initial - i * 30) / (180./TMath::Pi())) + north_x_offset, B0L1_34_r * sin((B0L1_point3_initial - i * 30) / (180./TMath::Pi())),
	  B0L1_34_r * cos((B0L1_point4_initial - i * 30) / (180./TMath::Pi())) + north_x_offset, B0L1_34_r * sin((B0L1_point4_initial - i * 30) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B0L1N"] = temp_vec; temp_vec.clear();

  // note : B1L0N
  for (int i = 0; i <16; i++)
    {
      temp_vec.push_back({
	  B1L0_12_r * cos((B1L0_point1_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + north_x_offset, B1L0_12_r * sin((B1L0_point1_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_12_r * cos((B1L0_point2_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + north_x_offset, B1L0_12_r * sin((B1L0_point2_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_34_r * cos((B1L0_point3_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + north_x_offset, B1L0_34_r * sin((B1L0_point3_initial - i * 22.5 - 22.5) / (180./TMath::Pi())),
	  B1L0_34_r * cos((B1L0_point4_initial - i * 22.5 - 22.5) / (180./TMath::Pi())) + north_x_offset, B1L0_34_r * sin((B1L0_point4_initial - i * 22.5 - 22.5) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B1L0N"] = temp_vec; temp_vec.clear();

  // note : B1L1N
  for (int i = 0; i <16; i++)
    {
      temp_vec.push_back({
	  B1L1_12_r * cos((B1L1_point1_initial - i * 22.5) / (180./TMath::Pi())) + north_x_offset, B1L1_12_r * sin((B1L1_point1_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_12_r * cos((B1L1_point2_initial - i * 22.5) / (180./TMath::Pi())) + north_x_offset, B1L1_12_r * sin((B1L1_point2_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_34_r * cos((B1L1_point3_initial - i * 22.5) / (180./TMath::Pi())) + north_x_offset, B1L1_34_r * sin((B1L1_point3_initial - i * 22.5) / (180./TMath::Pi())),
	  B1L1_34_r * cos((B1L1_point4_initial - i * 22.5) / (180./TMath::Pi())) + north_x_offset, B1L1_34_r * sin((B1L1_point4_initial - i * 22.5) / (180./TMath::Pi()))
        });
    }
  ladder_pos_map["B1L1N"] = temp_vec; temp_vec.clear();
    
}

void TH2INTT::fill_ladder_line(){


  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B0L0S"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0S"][i].x1, ladder_pos_map["B0L0S"][i].y1, ladder_pos_map["B0L0S"][i].x2, ladder_pos_map["B0L0S"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0S"][i].x2, ladder_pos_map["B0L0S"][i].y2, ladder_pos_map["B0L0S"][i].x3, ladder_pos_map["B0L0S"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0S"][i].x3, ladder_pos_map["B0L0S"][i].y3, ladder_pos_map["B0L0S"][i].x4, ladder_pos_map["B0L0S"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0S"][i].x4, ladder_pos_map["B0L0S"][i].y4, ladder_pos_map["B0L0S"][i].x1, ladder_pos_map["B0L0S"][i].y1 ));
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B0L1S"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1S"][i].x1, ladder_pos_map["B0L1S"][i].y1, ladder_pos_map["B0L1S"][i].x2, ladder_pos_map["B0L1S"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1S"][i].x2, ladder_pos_map["B0L1S"][i].y2, ladder_pos_map["B0L1S"][i].x3, ladder_pos_map["B0L1S"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1S"][i].x3, ladder_pos_map["B0L1S"][i].y3, ladder_pos_map["B0L1S"][i].x4, ladder_pos_map["B0L1S"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1S"][i].x4, ladder_pos_map["B0L1S"][i].y4, ladder_pos_map["B0L1S"][i].x1, ladder_pos_map["B0L1S"][i].y1 )); 
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B1L0S"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0S"][i].x1, ladder_pos_map["B1L0S"][i].y1, ladder_pos_map["B1L0S"][i].x2, ladder_pos_map["B1L0S"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0S"][i].x2, ladder_pos_map["B1L0S"][i].y2, ladder_pos_map["B1L0S"][i].x3, ladder_pos_map["B1L0S"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0S"][i].x3, ladder_pos_map["B1L0S"][i].y3, ladder_pos_map["B1L0S"][i].x4, ladder_pos_map["B1L0S"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0S"][i].x4, ladder_pos_map["B1L0S"][i].y4, ladder_pos_map["B1L0S"][i].x1, ladder_pos_map["B1L0S"][i].y1 )); 
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B1L1S"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1S"][i].x1, ladder_pos_map["B1L1S"][i].y1, ladder_pos_map["B1L1S"][i].x2, ladder_pos_map["B1L1S"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1S"][i].x2, ladder_pos_map["B1L1S"][i].y2, ladder_pos_map["B1L1S"][i].x3, ladder_pos_map["B1L1S"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1S"][i].x3, ladder_pos_map["B1L1S"][i].y3, ladder_pos_map["B1L1S"][i].x4, ladder_pos_map["B1L1S"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1S"][i].x4, ladder_pos_map["B1L1S"][i].y4, ladder_pos_map["B1L1S"][i].x1, ladder_pos_map["B1L1S"][i].y1 )); 
  }



  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B0L0N"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0N"][i].x1, ladder_pos_map["B0L0N"][i].y1, ladder_pos_map["B0L0N"][i].x2, ladder_pos_map["B0L0N"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0N"][i].x2, ladder_pos_map["B0L0N"][i].y2, ladder_pos_map["B0L0N"][i].x3, ladder_pos_map["B0L0N"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0N"][i].x3, ladder_pos_map["B0L0N"][i].y3, ladder_pos_map["B0L0N"][i].x4, ladder_pos_map["B0L0N"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L0N"][i].x4, ladder_pos_map["B0L0N"][i].y4, ladder_pos_map["B0L0N"][i].x1, ladder_pos_map["B0L0N"][i].y1 )); 
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B0L1N"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1N"][i].x1, ladder_pos_map["B0L1N"][i].y1, ladder_pos_map["B0L1N"][i].x2, ladder_pos_map["B0L1N"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1N"][i].x2, ladder_pos_map["B0L1N"][i].y2, ladder_pos_map["B0L1N"][i].x3, ladder_pos_map["B0L1N"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1N"][i].x3, ladder_pos_map["B0L1N"][i].y3, ladder_pos_map["B0L1N"][i].x4, ladder_pos_map["B0L1N"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B0L1N"][i].x4, ladder_pos_map["B0L1N"][i].y4, ladder_pos_map["B0L1N"][i].x1, ladder_pos_map["B0L1N"][i].y1 ));  
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B1L0N"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0N"][i].x1, ladder_pos_map["B1L0N"][i].y1, ladder_pos_map["B1L0N"][i].x2, ladder_pos_map["B1L0N"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0N"][i].x2, ladder_pos_map["B1L0N"][i].y2, ladder_pos_map["B1L0N"][i].x3, ladder_pos_map["B1L0N"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0N"][i].x3, ladder_pos_map["B1L0N"][i].y3, ladder_pos_map["B1L0N"][i].x4, ladder_pos_map["B1L0N"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L0N"][i].x4, ladder_pos_map["B1L0N"][i].y4, ladder_pos_map["B1L0N"][i].x1, ladder_pos_map["B1L0N"][i].y1 )); 
  }

  // note : fill the bin line, to show the shape
  for (int i = 0; i < ladder_pos_map["B1L1N"].size(); i++) { 
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1N"][i].x1, ladder_pos_map["B1L1N"][i].y1, ladder_pos_map["B1L1N"][i].x2, ladder_pos_map["B1L1N"][i].y2 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1N"][i].x2, ladder_pos_map["B1L1N"][i].y2, ladder_pos_map["B1L1N"][i].x3, ladder_pos_map["B1L1N"][i].y3 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1N"][i].x3, ladder_pos_map["B1L1N"][i].y3, ladder_pos_map["B1L1N"][i].x4, ladder_pos_map["B1L1N"][i].y4 ));
    ladder_line.push_back(new TLine(ladder_pos_map["B1L1N"][i].x4, ladder_pos_map["B1L1N"][i].y4, ladder_pos_map["B1L1N"][i].x1, ladder_pos_map["B1L1N"][i].y1 )); 
  }


}

void TH2INTT::fill_ladder_toinfo_map_bin(){

  TString side_word;
  int bin_index = 1;

  for (int arm = 0; arm < 2; arm++) // note : arm, 0 for south, 1 for north
    {
      side_word = (arm == 0) ? "S" : "N";

      for (int layer = 0; layer < 4; layer++) // note : layer
        {   
	  int n_ladder = (layer < 2) ? 12 : 16;

	  for (int HL = 0; HL < n_ladder; HL++)
            {
	      ladder_toinfo_map
		[
		 Form("%s%s%s",
		      layer_map.at(layer).Data(),
		      index_word[HL].Data(),
		      side_word.Data() )
		 ].bin_id = bin_index;

	      // cout<<Form("%s%s%s",layer_map.at(layer).Data(),index_word[HL].Data(),side_word.Data())<<" "<<bin_index<<endl;

	      bin_index += 1;
            }

	  // cout<<" "<<endl;

        }
      // cout<<" "<<endl;
    }
    
}

void TH2INTT::SetLadderSContent(TString ladder_name, double content)
{
  TH2Poly::SetBinContent(ladder_toinfo_map.at(ladder_name).bin_id, content);   
}

void TH2INTT::SetSerFCSContent(TString server_FC, double content)
{
  TH2Poly::SetBinContent(ladder_toinfo_map.at( serverFC_toinfo_map.at(server_FC).Ladder ).bin_id, content);
}

void TH2INTT::SetLadderIContent(int barrel_id, int layer_id, int ladder_id, int side, double content)
{
  if (side != 0 && side != 1) {
    cout<<"wrong side fill"<<endl;
    return;
  }

  TString side_word = (side == 0) ? "S" : "N";
  // cout<<Form("B%iL%i%s%s",barrel_id,ladder_id,index_word[ladder_id].Data(),side_word.Data())<<endl;
  TH2Poly::SetBinContent(ladder_toinfo_map.at(Form("B%iL%i%s%s",barrel_id,layer_id,index_word[ladder_id].Data(),side_word.Data())).bin_id, content);   
}

void TH2INTT::SetSerFCIContent(int server_id, int FC_id, double content)
{
  TH2Poly::SetBinContent(ladder_toinfo_map.at( serverFC_toinfo_map.at(Form("intt%i_%i",server_id,FC_id)).Ladder ).bin_id, content);
}



double TH2INTT::GetLadderSContent(TString ladder_name)
{
  return TH2Poly::GetBinContent(ladder_toinfo_map.at(ladder_name).bin_id);   
}

double TH2INTT::GetSerFCSContent(TString server_FC)
{
  return TH2Poly::GetBinContent(ladder_toinfo_map.at( serverFC_toinfo_map.at(server_FC).Ladder ).bin_id);
}

double TH2INTT::GetLadderIContent(int barrel_id, int layer_id, int ladder_id, int side)
{
  if (side != 0 && side != 1) {
    cout<<"wrong side fill"<<endl;
    return 0;
  }

  TString side_word = (side == 0) ? "S" : "N";
  return TH2Poly::GetBinContent(ladder_toinfo_map.at(Form("B%iL%i%s%s",barrel_id,layer_id,index_word[ladder_id].Data(),side_word.Data())).bin_id);   
}

double TH2INTT::GetSerFCIContent(int server_id, int FC_id)
{
  return TH2Poly::GetBinContent(ladder_toinfo_map.at( serverFC_toinfo_map.at(Form("intt%i_%i",server_id,FC_id)).Ladder ).bin_id);
}


